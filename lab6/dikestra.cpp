#include <iostream>
using namespace std;

#define V 5
#define INF 99999

// Find vertex with minimum distance
int minDistance(int dist[], bool visited[])
{
    int min = INF, min_index;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print path using parent array
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
    {
        cout << j;
        return;
    }

    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];
    int parent[V];

    // Initialization
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    // Main algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print results
    cout << "Vertex\tShortest Distance\tPath\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    dijkstra(graph, 0);

    return 0;
}