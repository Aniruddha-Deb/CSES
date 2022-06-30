#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;
    vector<int> H(n+1), S(n+1);
    for (int i=1; i<n+1; i++) cin >> H[i];
    for (int i=1; i<n+1; i++) cin >> S[i];

    // Knapsack DP: memoize the maximum number of pages we can buy in the first 
    // k books with maximum price p 
    // then: 
    //  DP[0][0] = 0;
    //  DP[k][p] = DP[k-1][p] if price[k] > p
    //  DP[k][p] = max(DP[k-1][p], DP[k-1][p-price[k]] + pages[k]), price[k] <= p
    // final answer will be DP[n][x]

    vector<vector<int>> DP(n+1,vector<int>(x+1,0));
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<x+1; j++) {
            if (H[i] <= j) {
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-H[i]] + S[i]);
            }
            else {
                DP[i][j] = DP[i-1][j];   
            }
        }
    }

    cout << DP[n][x] << endl;

    return 0;
}