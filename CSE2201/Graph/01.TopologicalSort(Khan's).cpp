#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>indeg(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto it:adj[u]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    for(auto it: topo){
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;

}
/*input:
5 4
0 1
0 2
1 3
3 4

output: 
0 1 2 3 4 
*/