import sys

def dijkstra(graph):
    n = len(graph)
    dist = [sys.maxsize] * n
    dist[0] = 0
    visited = set()

    def minDistance():
        min_ans, min_index = min((dis, i) for i, dis in enumerate(dist) \
                                     if i not in visited)
        return min_index
    
    for _ in range(n):
        min_index = minDistance()

        visited.add(min_index)
        for v in range(n):
            if v not in visited and graph[min_index][v] > 0:
                new_dist = dist[min_index] + graph[min_index][v]
                if dist[v] > new_dist:
                    dist[v] = new_dist

    print(dist)
        
#test
graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
         [4, 0, 8, 0, 0, 0, 0, 11, 0],
         [0, 8, 0, 7, 0, 4, 0, 0, 2],
         [0, 0, 7, 0, 9, 14, 0, 0, 0],
         [0, 0, 0, 9, 0, 10, 0, 0, 0],
         [0, 0, 4, 14, 10, 0, 2, 0, 0],
         [0, 0, 0, 0, 0, 2, 0, 1, 6],
         [8, 11, 0, 0, 0, 0, 1, 0, 7],
         [0, 0, 2, 0, 0, 0, 6, 7, 0]]
 
dijkstra(graph)
