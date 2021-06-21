#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

#ifdef DEBUG
#define debug(x) cout << x
#else
#define debug(x) 
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll dp[5005][5005];

ll max_sum(vi const& A, int i, int j, int turn) {
	if (turn == 1) {
		if (dp[i][j] != LONG_MIN) return dp[i][j];
		// player 1's turn
		if (j == 1) {
			dp[i][j] = A[i];
			return A[i];
		}
		else {
			dp[i][j] = max(max_sum(A,i+1,j-1,2)+A[i], max_sum(A,i,j-1,2)+A[i+j-1]);
			return dp[i][j];
		}
	}
	else {
		// player 2's turn
		if (j == 1) return 0;
		else {
			return min(max_sum(A,i+1,j-1,1), max_sum(A,i,j-1,1));
		}
	}
}

int main() {
	init();
	int n;
	cin >> n;
	vi A(n);
	forn(n) cin >> A[i];
	
	for(int i=0; i<n+5; i++) {
		for (int j=0; j<n+5; j++) {
			dp[i][j] = LONG_MIN;
		}
	}

	cout << max_sum(A,0,n,1) << endl;
	return 0;
}
