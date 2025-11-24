#include <bits/stdc++.h>
using namespace std;
int const mx = 1001;
int const INF = 1e9;
int main()
{
    int n, m; // n = nodes, m = edges
    cin >> n >> m;
    int adj[n][n]; // let take node size matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    cout << "shortest sidtance between all pair:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INF)
            {
                cout << "inf" << " ";
            }
            else
            {
                cout << adj[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
/*
input:
4 4
0 1 5
0 3 10
1 2 3
2 3 1
output: 
shortest sidtance between all pair:
0 5 8 9 
inf 0 3 4 
inf inf 0 1 
inf inf inf 0 
*/