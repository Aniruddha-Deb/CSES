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
	int n, k;
	cin >> n >> k;
	vi A(n);
	vi DP(k+1, -1);
	forn (n) {
		int temp;
		cin >> temp;
		A.push_back(temp);
		if (temp <= k) DP[temp] = 1;
	}

	sort(A.begin(), A.end());
	for (int i=A[0]+1; i<=k; i++) {
		if (DP[i] == 1) continue;
		for (int j : A) {
			if (i-j > 0 && DP[i-j] != -1) {
				if (DP[i] != -1 && DP[i-j]+1 < DP[i]) {
					DP[i] = DP[i-j] + 1;
				}
				else if (DP[i] == -1) DP[i] = DP[i-j] + 1;
			}
		}
	}

	//for (int i : DP) cout << i << " ";
	//cout << endl;
	cout << DP[k] << endl;

	return 0;
}
