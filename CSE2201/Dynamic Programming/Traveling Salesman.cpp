#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> cost[i][j];

    int N = 1<<n;
    vector<vector<int>> dp(N, vector<int>(n, INF));

    dp[1][0] = 0; // starting from city 0

    for(int mask=1; mask<N; mask++){
        for(int u=0; u<n; u++){
            if(!(mask & (1<<u))) continue;
            for(int v=0; v<n; v++){
                if(mask & (1<<v)) continue;
                int nextMask = mask | (1<<v);
                dp[nextMask][v] = min(dp[nextMask][v],
                                      dp[mask][u] + cost[u][v]);
            }
        }
    }

    int ans = INF;
    for(int i=0;i<n;i++)
        ans = min(ans, dp[N-1][i] + cost[i][0]);

    cout << "TSP Minimum Cost = " << ans;
}
