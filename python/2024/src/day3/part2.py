import re
import math


def getProductSum(matches):
    pattern = "\d{1,3},\d{1,3}"
    total = 0
    add = True
    for i in matches:
        if i == "don't()":
            add = False
        elif i == "do()":
            add = True
            continue
        if add:
            total += math.prod(
                [int(num) for num in re.findall(pattern, i)[0].split(",")]
            )
    return total


with open("input/myInput.txt", "r") as fhand:
    puzzle = fhand.read()

pattern = re.compile("mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\)")
matches = re.findall(pattern, puzzle)
sum_ = getProductSum(matches)
print(sum_)
