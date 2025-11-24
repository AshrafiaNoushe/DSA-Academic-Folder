#include<bits/stdc++.h>
using namespace std;

int limit = 5;
int spilt = 0;

int const mx = 100001;
vector<pair<int,int>>adj[mx];

int dfs(int node, int parent){
    vector<int>childPaths;
    for(auto it: adj[node]){
        int child = it.first;
        int w = it.second;
        if(child == parent) continue;
        int childpath = dfs(child,node)+w;
        childPaths.push_back(childpath);
    }
    int maxi = INT_MIN;
    int sum =0;
    for(auto it:childPaths){
        if(sum+it<=limit){
            sum+=it;
            maxi = max(it,maxi); // we are just finding max single path
        }else{
            spilt++;//When a child path cannot fit in the current group
        }
    }
    return maxi;

}
int main()
{
int n;
cin>>n>>limit; //n = total nodes

for (int i = 1; i <= n; i++) adj[i].clear(); // to clear the gurbage;

for(int i=1;i<=n-1;i++){ // i am counting edges so alway n-1 edges
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});//edges
    adj[v].push_back({u,w});//edges
}
dfs(1,-1);// 1 mean root node, -1 mean no parent
cout<<"max spilt: "<<spilt<<endl;
return 0;
}
/*
input:
7 6
1 2 3
1 3 4
2 4 3
2 5 2
3 6 3
3 7 3

output: 0
*/