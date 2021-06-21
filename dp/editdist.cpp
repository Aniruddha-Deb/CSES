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

int main() {
	init();
	string s1, s2;
	cin >> s1 >> s2;
	string sl = s1.length() > s2.length() ? s1 : s2;
	string ss = s1.length() > s2.length() ? s2 : s1;

	// find the longest common subsequence between the two strings; the edit
	// distance is (ll-lcs)

	vector<vi> DP(s1.length()+1, vi(s2.length()+1,0));

	for (int i=1; i<=s1.length(); i++) {
		DP[i][0] = i;
	}
	for (int j=1; j<=s2.length(); j++) {
		DP[0][j] = j;
	}
	for (int i=1; i<=s1.length(); i++) {
		for (int j=1; j<=s2.length(); j++) {
			if (s1[i-1] == s2[j-1]) DP[i][j] = DP[i-1][j-1];
			else DP[i][j] = min(min(DP[i][j-1]+1, DP[i-1][j]+1), DP[i-1][j-1]+1);
		}
	}
	for (auto v : DP) {
		for (int i : v) {
			debug(i << " ");
		}
		debug(endl);
	}
	cout << DP[s1.length()][s2.length()] << endl;
	return 0;
}
