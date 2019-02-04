#Name: Kassim Izuagbe
#Student ID: 100129353
#Email: 129353i@acadiau.ca
#Class: COMP 2113 X1
#Assignment: 5

import argparse

arr = []
parser = argparse.ArgumentParser()
parser.add_argument("it")
args = parser.parse_args()
file = open(args.it, "r")
for line in file:
    arr.append(line.rstrip('\n'))
#print(arr)
for x in range((len(arr))):
    if (arr[x] < arr[x+1]):
        temp = arr[x]
        arr[x] = arr[x+1]
        arr[x+1] = temp
print(arr)

file.close()

        