#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return (double)(a[1])/a[0] >= (double)(b[1])/b[0];
}

double snapSack(vector<vector<int>> &products, int capacity, int n) {
    sort(products.begin(), products.end(), cmp);
    double profit = 0;
    for(int i = 0; i < n; i++) {
        if(products[i][0] <= capacity) {
            profit += products[i][1];
            capacity -= products[i][0];
        }
        else {
            profit += (double)products[i][1]*capacity/products[i][0];
            capacity = 0;
            break;
        }
    }
    return profit;
}

int main() {
    int n, capacity;
    cout << "Enter number of product";
    cin >> n;
    vector<vector<int>> products(n, vector<int> (2, 0));
    cout << "Enter weights of the product : " << endl;
    for(int i = 0; i < n; i++)
        cin >> products[i][0];
    cout << "Enter profits of the product" << endl;
    for(int i = 0; i < n; i++)
        cin >> products[i][1];
    cout << "Enter total capacity : " << endl;
    cin >> capacity;
    cout << "Maximum profit can be achived is : " << snapSack(products, capacity, n) << endl;
    return 0;
}