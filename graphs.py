
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

#adjacency list representation of a graph

class LlNode:
    def __init__(self, vertex):
        self.vertex = vertex
    vertex: str
    next: 'LlNode' = None

graph = {
    "A": LlNode("A"),
    "B": LlNode("B"),
    "C": LlNode("C"),
    "D": LlNode("D")
    }

graph["A"].next = LlNode("B")
graph["A"].next.next = LlNode("C")

print(graph["A"].next.vertex)
print(graph["A"].next.next.vertex)
print(graph["A"].next.next.next)
