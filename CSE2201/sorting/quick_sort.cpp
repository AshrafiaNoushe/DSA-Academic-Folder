#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int low,int high){
    int pivot = v[high];
    int i = low -1; //index = -1;
    for(int j=low;j<high;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[high]);
    return i+1;
}
void quick_sort(vector<int>&v,int low,int high){
    if(low<high){
        int pi = partition(v,low,high);
        quick_sort(v,low,pi-1); //notice
        quick_sort(v,pi+1,high); //notice
    }
}
int main()
{
    vector<int>v = {70,30,50,10};
    int n = v.size();
    quick_sort(v,0,n-1); // pass h = size -1
    for(auto it:v){
        cout<<it<<" "; //not v[it], here it its element itself
    }
    return 0;
}