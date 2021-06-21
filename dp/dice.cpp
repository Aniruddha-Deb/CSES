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
	
	vi DP(n+1, 0);
	DP[0] = 0;
	DP[1] = 1;
	for (int i=2; i<=n; i++) {
		if(i<=6) DP[i]++;
		for (int j=6; j>0; j--) {
			if (i-j > 0) DP[i] = (DP[i] + DP[i-j])%MOD;
		}
	}
/*	
	for (int i : DP) {
		cout << i << " ";
	}
	cout << endl;*/
	cout << DP[n] << endl;
			
	return 0;
}
