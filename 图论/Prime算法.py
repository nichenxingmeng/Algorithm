from collections import defaultdict
import heapq

def prim(vertexs, edges):
    tmp = defaultdict(list)
    for v1, v2, length in edges:
        tmp[v1].append((length, v1, v2))
        tmp[v2].append((length, v2, v1))

    res = []

    visited = set(vertexs[0])

    tmp_edges = tmp[vertexs[0]]

    heapq.heapify(tmp_edges)

    while tmp_edges:
        w, v1, v2 = heapq.heappop(tmp_edges)
        if v2 not in visited:
            visited.add(v2)

            res.append((v1, v2, w))

            for next_ in tmp[v2]:
                if next_[2] not in visited:
                    heapq.heappush(tmp_edges, next_)

    return res

#test
vertexs = list("ABCDEFG")
edges = [("A", "B", 7), ("A", "D", 5),
         ("B", "C", 8), ("B", "D", 9),
         ("B", "E", 7), ("C", "E", 5),
         ("D", "E", 15), ("D", "F", 6),
         ("E", "F", 8), ("E", "G", 9),
         ("F", "G", 11)]
 
print("edges:", edges)
print("prim:", prim(vertexs, edges))
