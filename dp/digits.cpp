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

ll reduce(int n) {
	int md = 0;
	int k = n;
	while (k > 0) {
		int d = k%10;
		if (d > md) md = d;
		k /= 10;
	}
	if (md == 0) return 0;
	return 1 + reduce(n-md);
}

int main() {
	init();
	int n;
	cin >> n;
	cout << reduce(n) << endl;
	return 0;
}
