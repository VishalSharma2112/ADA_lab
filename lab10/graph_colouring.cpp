#include <iostream>
using namespace std;

#define V 4

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool solve(int v, bool graph[V][V], int m, int color[]) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (solve(v + 1, graph, m, color))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    bool graph[V][V] = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int color[V] = {0};
    int m = 3;

    if (!solve(0, graph, m, color)) {
        cout << "Solution does not exist";
        return 0;
    }

    for (int i = 0; i < V; i++)
        cout << color[i] << " ";

    return 0;
}