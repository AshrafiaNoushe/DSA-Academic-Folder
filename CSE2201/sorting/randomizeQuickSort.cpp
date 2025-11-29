#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int l,int r){
    int randomInd = l+rand()%(r-l);
    swap(v[r],v[randomInd]);
    int pivot = v[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(pivot>=v[j]){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
}
void randomizedQsort(vector<int>&v,int l,int r){
    if(l<r){
        int pi = partition(v,l,r);
        randomizedQsort(v,0,pi-1);
        randomizedQsort(v,pi+1,r);

    }

}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    randomizedQsort(v,0,n-1);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}