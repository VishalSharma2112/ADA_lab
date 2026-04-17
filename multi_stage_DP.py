import math

def multistage_graph(cost, n):
    
    dist = [math.inf] * n
    path = [-1] * n

    dist[n-1] = 0
    for i in range(n-2, -1, -1):
        for j in range(i+1, n):
            if cost[i][j] != math.inf:
                if cost[i][j] + dist[j] < dist[i]:
                    dist[i] = cost[i][j] + dist[j]
                    path[i] = j

    print("Minimum cost:", dist[0])

    print("Path:", end=" ")
    node = 0
    while node != -1:
        print(node, end=" ")
        node = path[node]
    print()
    

INF = math.inf
cost = [
    [INF, 1, 2, 5, INF, INF],
    [INF, INF, INF, INF, 4, 11],
    [INF, INF, INF, INF, 9, 5],
    [INF, INF, INF, INF, INF, 2],
    [INF, INF, INF, INF, INF, INF],
    [INF, INF, INF, INF, INF, INF]
]

n = len(cost)

multistage_graph(cost, n)