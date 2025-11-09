#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n-1;i++){ //notice
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                minIndex = j;
            }
        }
        swap(v[i],v[minIndex]);
    }

}
int main()
{
    vector<int>v = {70,30,50,10};
    selection_sort(v); // pass h = size -1
    for(auto it:v){
        cout<<it<<" "; //not v[it], here it its element itself
    }
    return 0;
}