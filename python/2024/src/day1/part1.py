# Read the input from a file
with open("../../../../input/testInput.txt", "r", encoding="utf-8") as puzzleDataHandle:
    data = [line.strip().split("  ") for line in puzzleDataHandle.readlines()]

col1, col2 = [
    sorted([int(fCol[0]) for fCol in data]),
    sorted([int(sCol[1]) for sCol in data]),
]
totalDistance = 0
for i in range(len(col1)):
    totalDistance += abs(col1[i] - col2[i])
print(totalDistance)
