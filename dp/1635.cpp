// Consider a money system consisting of n coins. Each coin has a positive 
// integer value. Your task is to calculate the number of distinct ways you can 
// produce a money sum x using the available coins.
 
#include <bits/stdc++.h>
 
#define MOD 1000000007
 
using namespace std;
 
int main() {
 
    int n, x;
    cin >> n >> x;
 
    vector<int> A(n);
    for (int i=0; i<n; i++) cin >> A[i];
 
    vector<long long> DP(x+1,0);
 
    DP[0] = 1;

    for (int i=1; i<=x; i++) {
        for (int j: A) {
            if (i-j >= 0) {
                DP[i] += DP[i-j];
            }
        }
        DP[i] %= MOD;
    }
 
    cout << DP[x] << endl;
 
    return 0;
}