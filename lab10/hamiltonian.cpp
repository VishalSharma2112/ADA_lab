#include <iostream>
using namespace std;

#define V 5

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool solve(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        return graph[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (solve(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    int graph[V][V] = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (!solve(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists";
        return 0;
    }

    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0];

    return 0;
}