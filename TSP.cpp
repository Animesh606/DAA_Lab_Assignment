#include <bits/stdc++.h>
using namespace std;

int tsp(int k, vector<vector<int>> &mat, unordered_set<int> st) {
    
}

int main() {
    int n, k;
    cin >> n;
    vector<vector<int>> mat(n, vector<int> (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    cin >> k;
    unordered_set<int> st;
    for(int i = 0; i < n; i++)
        st.insert(i);
    st.erase(k);
    vector<int> ans = {0};
    int cost = tsp(k, mat, st);
    cout << cost << endl;
    for(auto i : ans)
        cout << i << " ";
    return 0;
}