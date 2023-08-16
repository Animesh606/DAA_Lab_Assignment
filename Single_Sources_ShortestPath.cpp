#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> formGraph(int n, int e)
{
    vector<vector<int>> adj(e);
    cout << "Enter all the edges in form (from-to-cost) :" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i] = {u, v, w};
    }
    return adj;
}

void showGraph(vector<vector<int>> &G, int n)
{
    for (int i = 0; i < n; i++)
        cout << "Shortest path from " << i + 1 << " to " << j + 1 << " is : " << G[i][j] << endl;
}

vector<int> bellmanford(vector<vector<int>> &G, int n, int s) {
    vector<int> paths(n, INT_MAX);
    paths[s - 1] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(auto &it : G) {
            if(paths[it[0]] != INT_MAX)
                paths[it[1]] = min(paths[it[1]], paths[it[1]] + it[2]);
        }
    }
    for(auto &it : G) {
        if(path[it[1]] != INT_MAX && paths[it[1]] > paths[it[0]] + it[2])
    }
}

int main() {
    int n, e, source;
    cout << "Enter number of vertex : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> e;
    vector<vector<int>> G = formGraph(n, e);
    cout << "Enter the souce vertex : ";
    cin >> source;
    vector<int> shortedPath = bellmanford(G, n, source);
    return 0;
}