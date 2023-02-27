// shreyash_11
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adjList;

public:
    Graph(int n) {
        this->n = n;
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS() {
        queue<int> q;
        vector<bool> discovered(n, false);

        for(int i=0; i<n; i++) {
            if(!discovered[i]){
                discovered[i]=true;
                q.push(i);
                BFS(q, discovered);
            }
        }

        cout << endl;
    }

    void BFS(queue<int>& q, vector<bool>& discovered) {
        if(q.empty()) return;

        int u = q.front();
        q.pop();

        cout << u << " ";

        for(auto v : adjList[u]) {
            if(!discovered[v]) {
                discovered[v]=true;
                q.push(v);
            }
        }

        BFS(q, discovered);
    }

    void DFS() {
        vector<bool> visited(n, false);
        int start = 0;
        DFS(start, visited);
        cout << endl;
    }

    void DFS(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for(auto v : adjList[u]) {
            if(!visited[v]) DFS(v, visited);
        }
    }
};

void solve(){
    int n; cin>>n;
    Graph g(n);
    
    int e; cin>>e;
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.BFS();
    g.DFS();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin >> t;
    for(int i=1; i<=t; i++) {
        solve();
    }
    return 0;
}

/*
4 6
0 1
0 2
1 2
2 0
2 3
3 3

expected o/p:
bfs: 0 1 2 3
dfs(1): 1 0 2 3
*/
