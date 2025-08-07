
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

def graph_bfs():

    graph = {
        "A": LlNode("A"),
        "B": LlNode("B"),
        "C": LlNode("C"),
        "D": LlNode("D")
        }

    graph["A"].next = LlNode("B")
    graph["A"].next.next = LlNode("C")
    graph["B"].next = LlNode("C")
    graph["C"].next = LlNode("D")
    graph["D"].next = LlNode("B")

    queue = []
    visited = set()
    queue.append("A")

    while len(queue)>0:
        print("\n")

        current_node = queue.pop(0)
        print("current node: " + current_node)
        if current_node in visited:
            print("already visited: " + current_node)
            continue
        else:
            adjacent_node = graph[current_node].next
            while adjacent_node != None:
                if adjacent_node.vertex not in visited:
                    print("adding " + adjacent_node.vertex + " to queue")
                    queue.append(adjacent_node.vertex)
                else:
                    print("already visited: " + adjacent_node.vertex)
                adjacent_node = adjacent_node.next

            print("marking " + current_node + " as visited")
            visited.add(current_node)

            print(queue)

    print(queue)

def graph_dfs():

    graph = {
    "A": LlNode("A"),
    "B": LlNode("B"),
    "C": LlNode("C"),
    "D": LlNode("D"),
    "E": LlNode("E")
    }

    graph["A"].next = LlNode("B")
    graph["A"].next.next = LlNode("C")
    graph["A"].next.next.next = LlNode("E")
    graph["B"].next = LlNode("D")
    graph["C"].next = LlNode("D")
    graph["E"].next = LlNode("C")
    
    stack = []
    visited = set()

    stack.append("A")

    while len(stack)>0:
        print("\n")

        current_node = stack.pop()
        print("current node: " + current_node)
        if current_node in visited:
            print("already visited: " + current_node)
            continue
        else:
            adjacent_node = graph[current_node].next
            while adjacent_node != None:
                if adjacent_node.vertex not in visited:
                    print("adding " + adjacent_node.vertex + " to queue")
                    stack.append(adjacent_node.vertex)
                else:
                    print("already visited: " + adjacent_node.vertex)
                adjacent_node = adjacent_node.next

            print("marking " + current_node + " as visited")
            visited.add(current_node)

            print(stack)

    print(stack)

def calculate_in_node(graph):
    in_nodes = {}

    #dynamically create an empty in_nodes dict based on the graph
    for key in graph.keys():
        in_nodes[key] = 0

    for key, value in graph.items():
        print("key: " + key)
        while value.next !=None:
            in_nodes[value.next.vertex] += 1  #B = 1
            value = value.next
            print(in_nodes)
        print(" ")
    return in_nodes

def find_first_nodes(in_nodes):
    start_nodes = []
    for key, value in in_nodes.items():
        if value == 0:
            start_nodes.append(key)
    return start_nodes

def topological_sort():
    graph = {
        "A": LlNode("A"),
        "B": LlNode("B"),
        "C": LlNode("C"),
        "D": LlNode("D"),
        "E": LlNode("E")
    }

    seen = []

    graph["A"].next = LlNode("B")
    graph["A"].next.next = LlNode("C")
    graph["B"].next = LlNode("E")
    graph["C"].next = LlNode("B")
    graph["C"].next.next = LlNode("D")

    queue = []

    while len(graph) > 0:

        in_nodes = calculate_in_node(graph)
        start_nodes = find_first_nodes(in_nodes)
        print("start nodes: " + start_nodes.__str__())

        queue.extend(start_nodes)

        while len(queue) > 0:
            current_node = queue.pop(0)
            graph[current_node].next = None
            seen.append(current_node)
            del graph[current_node]
            del in_nodes[current_node]

        in_nodes = calculate_in_node(graph)

    print(seen)


topological_sort()