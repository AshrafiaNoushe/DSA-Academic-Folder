#include<bits/stdc++.h>
using namespace std;
pair<int,int>findMaxMin(vector<int>&v,int l,int r){
    if(l==r){
        return{v[l],v[l]};
    }else if(r==l+1){
        if(v[l]>v[r]){
            return{v[r],v[l]};
        }else{
            return {v[l],v[r]};
        }
    }
    int mid = (l+r)/2;
    pair<int,int>left=findMaxMin(v,0,mid);
    pair<int,int>right=findMaxMin(v,mid+1,r);
    int resultMin = min(left.first,right.first);
    int resultMax = max(left.second, right.second);
    return{resultMin,resultMax};
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    pair<int,int>result=findMaxMin(v,0,n-1);
    cout<<"Min and Max: "<<"\n";
    cout<<result.first<<" "<<result.second<<"\n";
    return 0;
}