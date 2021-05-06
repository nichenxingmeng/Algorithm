Inf = 65535
arr = [[0, 10, Inf, Inf, Inf, 11, Inf, Inf, Inf],
       [10, 0, 18, Inf, Inf, Inf, 16, Inf, 12],
       [Inf, 18, 0, 22, Inf, Inf, Inf, Inf, 8],
       [Inf, Inf, 22, 0, 20, Inf, Inf, 16, 21],
       [Inf, Inf, Inf, 20, 0, 26, Inf, 7, Inf],
       [11, Inf, Inf, Inf, 26, 0, 17, Inf, Inf],
       [Inf, 16, Inf, 24, Inf, 17, 0, 19, Inf],
       [Inf, Inf, Inf, 16, 7, Inf, 19, 0, Inf],
       [Inf, 12, 8, 21, Inf, Inf, Inf, Inf, 0]]

n = len(arr)
path = [[-1] * n for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if arr[i][j] > arr[i][k] + arr[k][j]:
                arr[i][j] = arr[i][k] + arr[k][j]
                path[i][j] = k

for x in arr:
    print(x)
print()
for x in path:
    print(x)
