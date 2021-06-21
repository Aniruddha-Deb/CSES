#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

#ifdef DEBUG
#define debug(x) cout << x;
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

int main() {
	init();
	int n;
	cin >> n;
	vi A(n);
	forn(n) cin >> A[i];
	
	vi DP(n+1,INT_MAX);
	DP[0] = INT_MIN;
	for (int i=0; i<n; i++) {
		int j = upper_bound(DP.begin(), DP.end(), A[i]) - DP.begin();
		if (DP[j-1] < A[i] && A[i] < DP[j]) DP[j] = A[i];
	}

	int ans = 1;
	for (int i=0; i<=n; i++) {
		if (DP[i] < INT_MAX) ans = i;
	}
	cout << ans << endl;
	return 0;
}
