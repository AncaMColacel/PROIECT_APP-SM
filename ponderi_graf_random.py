import random

rows = 50
cols = 50

matrix = [[random.randint(1, 1000) for _ in range(cols)] for _ in range(rows)]

for row in matrix:
    print(row)
