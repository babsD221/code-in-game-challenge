import sys
import math

def getArgumentsValues(listofValues,i):

    for arg in ["arg1","arg2"]:
        if listofValues[i][arg].startswith("$"):
            arg_index = int(listofValues[i][arg].split("$")[1])
            val = getArgumentsValues(listofValues,arg_index)
            listofValues[i][arg] = str(val)


    if listofValues[i]["operation"] == "ADD":
        return (int(listofValues[i]["arg1"])  + int(listofValues[i]["arg2"]) )
    elif listofValues[i]["operation"] == "SUB":
        return (int(listofValues[i]["arg1"])  - int(listofValues[i]["arg2"]) )

    elif listofValues[i]["operation"] == "MULT":
        return (int(listofValues[i]["arg1"])  * int(listofValues[i]["arg2"]) )

    else:

        return int(listofValues[i]["arg1"])
 

listofValues = list()
n = int(input())
for i in range(n):
    operation, arg_1, arg_2 = input().split()
    dict = {
        "operation":operation,
        "arg1":arg_1,
        "arg2":arg_2,
        "val": 0
    }
    listofValues.append(dict)

value = 0
for i in range(n):
    value = getArgumentsValues(listofValues,i)
    print(value)
