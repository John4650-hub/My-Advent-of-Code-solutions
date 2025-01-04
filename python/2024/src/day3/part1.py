import re
import math


def getProductSum(matches):
    pattern = "\d{1,3},\d{1,3}"
    total = 0
    for i in matches:
        total += math.prod([int(num) for num in re.findall(pattern, i)[0].split(",")])
    return total


with open("input/myInput.txt", "r") as fhand:
    puzzle = [i.strip() for i in fhand.readlines()]
sum_ = 0
pattern = "mul\(\d{1,3},\d{1,3}\)"
for corruptedTxt in puzzle:
    matches = re.findall(pattern, corruptedTxt)
    sum_ += getProductSum(matches)

print(sum_)
