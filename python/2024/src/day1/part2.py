with open("../../../../input/myInput.txt", "r", encoding="utf-8") as puzzleDataHandle:
    data = [line.strip().split("  ") for line in puzzleDataHandle.readlines()]

col1, col2 = [
    [int(fCol[0]) for fCol in data],
    [int(sCol[1]) for sCol in data]
]

similarityScore = 0
for i in col1:
    count =0
    for j in col2:
        if i==j:
            count+=1
        else:
            count+=0
    similarityScore += count*i

print(similarityScore)
