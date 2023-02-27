// shreyash_11
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
 
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    // Bellman Ford Algorithm, Single Source Shortest Path
    vector<int> dist(n+1, 1e9);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto [v, w]: adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
 
    for(int i=0; i<n; i++) cout << dist[i] << " ";
    cout << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin >> t;
    for(int i=1; i<=t; i++) {
        // cout << "Case #"<< i << ": " << solve() << endl;
        solve();
    }
    return 0;
}

/*
INPUT:
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 1 1
4 3 -3

EXPECTED OUPTPUT:
0 -1 2 -2 1
*/
