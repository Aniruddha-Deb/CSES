#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int n;
	cin >> n;
	vector<vi> grid(n, vi(n,0));
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<n; j++) {
			if (s[j] == '*') grid[i][j] = 1;
		}
	}

	// number of ways of getting to grid[i][j] 
	// = number of ways of getting to grid[i-1][j] 
	// + number of ways of getting to grid[i][j-1]
	// if [i][j] is not a trap;
	//
	// if [i][j] is a trap, then n = 0;
	vector<vector<int>> N(n, vector<int>(n, 0));
	if (!grid[0][0]) N[0][0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int nways = 0;
			if (grid[i][j] || (i==0&&j==0)) continue;
			if (j > 0) {
				nways += N[i][j-1];
				nways %= MOD;
			}
			if (i > 0) {
				nways += N[i-1][j];
				nways %= MOD;
			}
			N[i][j] = nways;
		}
	}
	#ifdef DEBUG
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << N[i][j] << " ";
		}
		cout << endl;
	}
	#endif
	cout << N[n-1][n-1] << endl;
			
	return 0;
}
