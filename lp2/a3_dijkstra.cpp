
void solve(){
    in(n) in(m)
 
    vector<vector<pll>> adj(n+1);
 
    for(int i=0; i<m; i++) {
        in(u) in(v) in(w)
        adj[u].push_back({v, w});
    }
 
    vector<ll> dist(n+1, 1e16);
    priority_queue<pll, vector<pll>, greater<>> q;
    q.push({0, 1});
    dist[1] = 0;
 
    while(!q.empty()) {
        auto [distance, u] = q.top();
        q.pop();
 
        if(distance != dist[u]) continue;
 
        for(auto [v, w]: adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = distance + w;
                q.push({dist[v], v});
            }
        }
    }
 
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    cout << endl;
}
