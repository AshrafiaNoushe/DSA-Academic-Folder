#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent, rnk;

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for(int i=0;i<m;i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    parent.resize(n);
    rnk.assign(n, 0);

    for(int i=0;i<n;i++) parent[i] = i;

    vector<Edge> mst;

    for(auto &e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            mst.push_back(e);
            unionSet(e.u, e.v);
        }
    }

    cout << "Edges in MST (using Kruskal):\n";
    int total = 0;

    for(auto &e : mst) {
        cout << e.u << " - " << e.v << " (weight = " << e.w << ")\n";
        total += e.w;
    }

    cout << "Total weight = " << total << endl;
}
