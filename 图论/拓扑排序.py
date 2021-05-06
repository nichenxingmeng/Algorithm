from collections import defaultdict

def findOrder(numCourses, prerequisites):
    graph = defaultdict(list)
    in_degree = defaultdict(int)

    for dest, src in prerequisites:
        graph[src].append(dest)
        in_degree[dest] += 1

    zero_degree = [k for k, v in in_degree.items() if v == 0]
    res = []
    while zero_degree:
        node = zero_degree.pop(0)
        res.append(node)
        for child in graph[node]:
            in_degree[child] -= 1
            if in_degree[child] == 0:
                zero_degree.append(child)

    return res