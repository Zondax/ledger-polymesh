/*******************************************************************************
 *   Polymesh Test Vector Output Capture Utility
 *
 *   Reads a JSON test vector file, parses each blob+metadata through the
 *   app_lib parser, captures the display output in normal and expert modes,
 *   and writes back the JSON with populated output/output_expert fields.
 *
 *   Usage: ./capture_output <path_to_json>
 *
 *   Build: cmake --build build/ --target capture_output
 *******************************************************************************/

#include <app_mode.h>
#include <hexutils.h>

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "parser.h"

using json = nlohmann::json;
using namespace std;

#define MAX_KEY_LEN       39U
#define MAX_VAL_LEN       39U
#define INPUT_BUFFER_SIZE 16384U

namespace {
vector<string> captureUI(parser_tx_t *txObj) {
    vector<string> answer;

    uint8_t numItems = 0;
    parser_error_t err = parser_getNumItems(txObj, &numItems);
    if (err != parser_ok) {
        return answer;
    }

    for (uint8_t idx = 0; idx < numItems; idx++) {
        char keyBuffer[MAX_KEY_LEN] = {0};
        char valueBuffer[MAX_VAL_LEN] = {0};
        uint8_t pageCount = 1;

        ui_field_t uiFields = {.displayIdx = idx,
                               .outKey = keyBuffer,
                               .outKeyLen = sizeof(keyBuffer),
                               .outVal = valueBuffer,
                               .outValLen = sizeof(valueBuffer),
                               .pageIdx = 0,
                               .pageCount = &pageCount};

        while (uiFields.pageIdx < *uiFields.pageCount) {
            stringstream ss;

            err = parser_getItem(txObj, &uiFields);

            ss << (int)idx << " | " << keyBuffer;
            if (pageCount > 1) {
                ss << " [" << (int)uiFields.pageIdx + 1 << "/" << (int)*uiFields.pageCount << "]";
            }
            ss << " : ";

            if (err == parser_ok) {
                ss << valueBuffer;
            } else {
                ss << parser_getErrorDescription(err);
            }

            answer.push_back(ss.str());
            uiFields.pageIdx++;
        }
    }

    return answer;
}
}  // namespace

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <path_to_json>" << endl;
        return 1;
    }

    const string jsonPath = argv[1];
    cout << "Reading: " << jsonPath << endl;

    // Read JSON
    ifstream inFile(jsonPath);
    if (!inFile.is_open()) {
        cerr << "ERROR: Cannot open " << jsonPath << endl;
        return 1;
    }

    json entries;
    try {
        inFile >> entries;
    } catch (const json::exception &e) {
        cerr << "ERROR: Failed to parse JSON: " << e.what() << endl;
        return 1;
    }
    inFile.close();

    // Support both wrapped format (with metadata) and plain array
    auto &vectors = entries.is_object() && entries.contains("vectors") ? entries["vectors"] : entries;

    cout << "Processing " << vectors.size() << " test vectors..." << endl;

    int successCount = 0;  // NOLINT(misc-const-correctness)
    int failCount = 0;     // NOLINT(misc-const-correctness)

    for (auto &entry : vectors) {
        const string name = entry["name"].get<string>();
        const string blobHex = entry["blob"].get<string>();
        const string metadataHex = entry["metadata"].get<string>();

        uint8_t inputBuffer[INPUT_BUFFER_SIZE] = {0};

        // Parse blob
        const size_t blobLen = parseHexString(inputBuffer, sizeof(inputBuffer), blobHex.c_str());
        if (blobLen == 0) {
            cerr << "  SKIP " << name << ": invalid blob hex" << endl;
            failCount++;
            continue;
        }

        // Parse metadata
        const size_t metadataLen = parseHexString(inputBuffer + blobLen, sizeof(inputBuffer) - blobLen, metadataHex.c_str());
        if (metadataLen == 0) {
            cerr << "  SKIP " << name << ": invalid metadata hex" << endl;
            failCount++;
            continue;
        }

        // Parse transaction
        parser_tx_t txObj = {0};
        parser_error_t err =
            parser_parse(&txObj, inputBuffer, static_cast<uint16_t>(blobLen + metadataLen), static_cast<uint16_t>(blobLen));

        if (err != parser_ok) {
            cerr << "  SKIP " << name << ": parse error: " << parser_getErrorDescription(err) << endl;
            failCount++;
            continue;
        }

        // Capture normal mode output
        app_mode_set_expert(0);
        vector<string> normalOutput = captureUI(&txObj);

        // Capture expert mode output
        app_mode_set_expert(1);
        vector<string> expertOutput = captureUI(&txObj);

        if (normalOutput.empty() && expertOutput.empty()) {
            cerr << "  SKIP " << name << ": empty output" << endl;
            failCount++;
            continue;
        }

        // Update JSON entry
        entry["output"] = normalOutput;
        entry["output_expert"] = expertOutput;

        cout << "  OK " << name << " (normal: " << normalOutput.size() << " lines, expert: " << expertOutput.size()
             << " lines)" << endl;

        successCount++;
    }

    // Write back
    ofstream outFile(jsonPath);
    if (!outFile.is_open()) {
        cerr << "ERROR: Cannot write to " << jsonPath << endl;
        return 1;
    }
    outFile << entries.dump(2);
    outFile.close();

    cout << "\n=== Done ===" << endl;
    cout << "Success: " << successCount << endl;
    cout << "Failed:  " << failCount << endl;
    cout << "Total:   " << vectors.size() << endl;
    cout << "Written: " << jsonPath << endl;

    return 0;
}
