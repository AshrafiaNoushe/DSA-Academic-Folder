#include<bits/stdc++.h>
using namespace std;
const int mx = 100001;
int limit =0;
vector<pair<int,int>> adjM[mx];
int split = 0;
int dfs(int node,int parent){
    int childPath =0;
    int maxPath =0;
    for(auto x: adjM[node]){
        int child = x.first;
        int weight = x.second;
        if(child==parent)continue;
        childPath = dfs(child,node) + weight; // child jabe as node and ager node as parent
        if(childPath>limit){
            split++;
        }else{
            maxPath = max(maxPath,childPath);
        }

    }
return maxPath;
}
int main()
{
    int u,v,w;
    int n; //nodes //edges n-1
    cin>>n;
    cin>>limit;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v>>w;
        adjM[u].push_back({v,w});
        adjM[v].push_back({u,w});
    }
    cout<<"Max path: "<<dfs(1,-1)<<" Total split: "<<split<<"\n";
    return 0;
}