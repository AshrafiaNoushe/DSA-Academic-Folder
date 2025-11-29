#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> cost;
map<pair<int, vector<bool>>, int> dp;   // DP state

int TSP(int u, vector<bool>& visited, int cnt) {

    if (cnt == n) {
        return cost[u][0];   // return to start
    }

    if (dp.count({u, visited})) {
        return dp[{u, visited}];
    }

    int ans = INF;

    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            visited[v] = true;

            ans = min(ans, cost[u][v] + TSP(v, visited, cnt + 1));

            visited[v] = false;
        }
    }

    return dp[{u, visited}] = ans;
}

int main() {
    cin >> n;

    cost.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vector<bool> visited(n, false);
    visited[0] = true;

    int answer = TSP(0, visited, 1);

    cout << "TSP Minimum Cost = " << answer;
}
/*
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
TSP Minimum Cost = 80*/