def floyd_warshal(graph):
    n = len(graph)
    dp = graph
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dp[i][k] == INF and dp[k][j] == INF:
                    continue
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

    print("After")
    for row in dp:
        for i in row:
            print(i, end="\t")
        print()


INF = float('inf')
graph = [
    [0, 3, INF, 7],
    [INF, 0, 1, INF],
    [INF, INF, 0, 2],
    [INF, 6, INF, 0]
]
print('Before')
for row in graph:
    for i in row:
        print(i, end="\t")
    print()
print()
floyd_warshal(graph)