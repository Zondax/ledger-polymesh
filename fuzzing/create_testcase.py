import json

with open("../tests/testcases_current.json") as json_file:
    data = json.load(json_file)
    for i in range(len(data)):
        f = open("corpus/tc_" + str(i), "wb")
        f.write(bytearray. fromhex(data[i]["blob"]))
        f.close()
