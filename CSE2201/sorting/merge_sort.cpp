#include<bits/stdc++.h>
using namespace std;
void merging(vector<int>&v,int low,int mid,int high){
    int n1 = mid-low+1;
    int n2 = high-mid;
    vector<int>L(n1),R(n2);
    for(int i=0;i<n1;i++){
        L[i] = v[low+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=v[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(n1>i && n2>j){ //the condition here just greater not equal
        if(L[i]<=R[j]){
            v[k] = L[i];
            i++;
            k++;
        }else{
            v[k]=R[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        v[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        v[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>&v,int low,int high){
    if(low<high){ //notice here if loop
        int mid = low+(high-low)/2;
        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);
        merging(v,low,mid,high);
    }
}
int main()
{
    vector<int>v = {70,30,50,10};
    int n = v.size();
    merge_sort(v,0,n-1); // pass h = size -1
    for(auto it:v){
        cout<<it<<" "; //not v[it], here it its element itself
    }
    return 0;
}