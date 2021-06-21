#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n;
	cin >> n;
	vi A;
	rep(i,0,n) {
		int temp;
		cin >> temp;
		// binary search for element
		// if index < n, insert in there
		// if index >= n, add it to the head of the list
		int l=0;
		int h = A.size();
		if (A.size() == 0) {
			A.push_back(temp);
			continue;
		}
		int m = 0;
		while (l <= h) {
			m = (l+h)/2;
			if (A[m] <= temp) l = m+1;
			else if (A[m] > temp) h = m-1;
		}
		// cout << "m = " << m << endl;
		if (m >= A.size() || (A[m] == temp && m == A.size()-1)) {
			A.push_back(temp);
		}
		else if (A[m] > temp) A[m] = temp;
		else if (A[m] <= temp) {
			// while (m < A.size() && A[m] <= temp) m++;
			// if (m == A.size()) A.push_back(temp);
			// else A[m] = temp;
			A[m+1] = temp;
		}

		// for (int k : A) cout << k << " ";
		// 	cout << endl;
	}

	cout << A.size() << endl;
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}