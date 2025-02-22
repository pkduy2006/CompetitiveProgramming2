#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const long long INF = 1e15 + 7;
int n, m, p[N];
vector<pair<int, int>> adj[N];
long long d[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    fill(p + 1, p + 1 + n, -1);
    fill(d + 1, d + 1 + n, INF);
    d[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if(du != d[u]) 
            continue;
        for(auto [v, w] : adj[u]) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                q.push({d[v], v});
            }
        }
    }
    if(d[n] == INF) 
        cout << -1;
    else {
        vector<int> path;
        for(int i = n; i != -1; i = p[i]) 
            path.push_back(i);
        reverse(path.begin(), path.end());
        for(int i : path) 
            cout << i << ' ';
    }

    return 0;
}