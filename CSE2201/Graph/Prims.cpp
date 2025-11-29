#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[10001];  // {neighbor, weight}
vector<int> key, parent;
vector<bool> inMST;

void prim(int n, int start) {
    key.assign(n, INT_MAX);
    parent.assign(n, -1);
    inMST.assign(n, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    key[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for(auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edges in MST (using Prim):\n";
    for(int i = 0; i < n; i++) {
        if(parent[i] != -1)
            cout << parent[i] << " - " << i << " (weight = " << key[i] << ")\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    prim(n, 0);
}
