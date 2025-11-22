#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int>&a,vector<int>&b){
    double a1 = (1.0*a[0])/a[1];
    double b1 = (1.0*b[0])/b[1];
    return a1>b1;
    /* in item={
    60, 10 // here it hold a[0],a[1]
    100,20 // here b[0] b[1]
    120,30 // sequentially 2ta row compare kore boro ta return debe 0,1 1,2 2,3 row num
    }*/
}
int frictional_kanpsack(vector<int>&p,vector<int>&w,int capacity){
    int n = p.size();
    vector<vector<int>>items(n,vector<int>(2));
    for(int i= 0; i<n;i++){ 
        items[i][0]= p[i];
        items[i][1] =w[i];
    }
    sort(items.begin(),items.end(),comp);
    double res = 0.0;
    int currCap = capacity;
    for(int i=0;i<n;i++){
        if(currCap>= items[i][1]){ // check if we call take whole weight
            res += items[i][0]; //add profit
            currCap-=items[i][1];
        } //if can't then take fractional;
        else{
            res+=((1.0 * items[i][0])/items[i][1])*currCap;
            break;
        }
    }
    return res;

}
int main()
{
    vector<int>profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    int total_profit =frictional_kanpsack(profit,weight,capacity);
    cout<<total_profit<<endl;
    return 0;
}