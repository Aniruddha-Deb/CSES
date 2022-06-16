#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n+1,vector<int>());

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    deque<int> S;
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,0);
    S.push_back(1);
    visited[1] = true;
    while (!S.empty()) {
        int v = S.front();
        S.pop_front();
        for (int i : G[v]) {
            if (!visited[i]) {
                S.push_back(i);
                parent[i] = v;
                visited[i] = true;
            }
        }
    }

    if(visited[n]) {
        vector<int> path;
        int v = n;
        while (v != 1) {
            path.push_back(v);
            v = parent[v];
        }
        cout << path.size()+1 << endl;
        cout << "1 ";
        for (int i=path.size()-1; i>=0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;

    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }

        for (int v : parent) {
            cout << v << " ";
        }
        cout << endl;


    return 0;
}