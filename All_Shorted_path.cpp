#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> formGraph(int n, int e)
{
    vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
    cout << "Enter all the edges in form (from-to-cost) :" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1][v - 1] = w;
    }
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    return adj;
}

void showGraph(vector<vector<int>> &G, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Shortest path from " << i + 1 << " to " << j + 1 << " is : " << G[i][j] << endl;
        }
    }
}

vector<vector<int>> floydWarshal(vector<vector<int>> G, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    return G;
}

int main()
{
    int n, e;
    cout << "Enter number of vertex : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> e;
    vector<vector<int>> G = formGraph(n, e);
    vector<vector<int>> shortedPath = floydWarshal(G, n);
    showGraph(shortedPath, n);
    return 0;
}