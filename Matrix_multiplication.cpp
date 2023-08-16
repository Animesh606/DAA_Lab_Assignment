#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, vector<vector<pair<int, int>>> &dp, int l, int r) {
    if(l == r)
        return 0;
    if(dp[l][r].second != -1)
        return dp[l][r].second;
    int mini = INT_MAX, p = 0;
    for(int i = l; i < r; i++) {
        p = arr[l - 1] * arr[i] * arr[r] + matrixMultiplication(arr, dp, l, i) + matrixMultiplication(arr, dp, i + 1, r);
        if(p < mini) {
            mini = p;
            dp[l][r].first = i;
        }
    }
    return dp[l][r].second = mini;
}

int main() {
    int n;
    cout << "Enter no of matrices : ";
    cin >> n;
    vector<int> arr(n);
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {0, -1}));
    cout << "Enter all Order of the matrices : " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Minimum no of multiplication occur : " << matrixMultiplication(arr, dp, 1, n - 1) << endl;
    cout << "Considering the dp : " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << dp[i][j].first << " ";
        cout << endl;
    }
    return 0;
}