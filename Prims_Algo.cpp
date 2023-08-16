#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> formGraph(int n, int e) {
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

class cmp {
    public:
        bool operator()(vector<int> A, vector<int> B) {
            return A[2] > B[2];
        }
};

vector<vector<int>> PrimAlgo(vector<vector<pair<int, int>>> &adj, int n) {
    unordered_set<int> vertex;
    vertex.insert(0);
    priority_queue<vector<int>, vector<vector<int>>, cmp> edges;
    for(auto it : adj[0]) {
        edges.push({0, it.first, it.second});
    }
    vector<vector<int>> ans;
    while(ans.size() < n - 1 && !edges.empty()) {
        vector<int> top = edges.top();
        edges.pop();
        if(vertex.find(top[0]) != vertex.end() && vertex.find(top[1]) == vertex.end()) {
            ans.push_back(top);
            vertex.insert(top[1]);
            for(auto it : adj[top[1]])
                edges.push({top[1], it.first, it.second});
        }
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
    vector<vector<pair<int, int>>> adj = formGraph(n, e);
    vector<vector<int>> minSpanTree = PrimAlgo(adj, n);
    cout << "The minimum Spanning Tree is " << endl;
    for(auto &it : minSpanTree) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
        minWeight += it[2];
    }
    cout << "The weight of the Spanning Tree is " << minWeight << endl;
    return 0;
}