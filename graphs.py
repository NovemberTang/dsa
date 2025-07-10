
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

visited = {
    "A": False,
    "B": False,
    "C": False,
    "D": False
}

graph["A"].next = LlNode("B")
graph["A"].next.next = LlNode("C")
graph["B"].next = LlNode("C")
graph["C"].next = LlNode("D")
graph["D"].next = LlNode("B")

queue = []

queue.append("A")

while len(queue)>0:

    current_node = queue.pop(0)
    if visited[current_node]:
        continue
    else:
        adjacent_node = graph[current_node].next
        while adjacent_node != None:
            if not visited[adjacent_node.vertex]:
                print("adding " + adjacent_node.vertex + " to queue")
                queue.append(adjacent_node.vertex)
            adjacent_node = adjacent_node.next

        visited[current_node] = True

        print(queue)

print(queue)
