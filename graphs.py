
#adjacency matrix representation of a graph

node_count = 4

nodemap = {
    "A": 0,
    "B": 1,
    "C": 2,
    "D": 3
}
matrix = []

for i in range(node_count):
    row = [None]*node_count
    matrix.append(row)

print("Matrix:", matrix)

matrix[nodemap["A"]][nodemap["A"]]= 1

for i in matrix:
    print(i)