#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> formGraph(int n, int e) {
    vector<vector<int>> adj;
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    return adj;
}

bool cmp(vector<int> &A, vector<int> &B) {
    return A[2] < B[2];
}


vector<vector<int>> kruskalAlgo(vector<vector<int>> &adj, int n) {
    sort(adj.begin(), adj.end(), cmp);
    unordered_set<int> vertex;
    vector<vector<int>> ans;
    for(auto &it : adj) {
        if(ans.size() < n - 1 && (vertex.find(it[0]) != vertex.end() || vertex.find(it[1]) != vertex.end()))
            ans.push_back(it);
    }
    return ans;
}


int main() {
    int n, e, minWeight = 0;
    cout << "Enter no of Vertex : ";
    cin >> n;
    cout << "Enter no of Edges : ";
    cin >> e;
    cout << "Enter all the Edges in (u-v-w) format" << endl;
    vector<vector<int>> adj = formGraph(n, e);
    vector<vector<int>> minSpanTree = kruskalAlgo(adj, n);
    cout << "The minimum Spanning Tree is " << endl;
    for(auto &it : minSpanTree) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
        minWeight += it[2];
    }
    cout << "The weight of the Spanning Tree is " << minWeight << endl;
    return 0;
}