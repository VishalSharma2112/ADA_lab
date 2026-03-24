#include <bits/stdc++.h>
using namespace std;

void stages(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    int stage = 0;

    while (!q.empty()) {
        int size = q.size();

        cout << "Stage " << stage << ": ";

        for (int i = 0; i < size; i++) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for (int j = 0; j < n; j++) {
                if (adj[node][j] == 1 && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }

        cout << endl;
        stage++;
    }
}