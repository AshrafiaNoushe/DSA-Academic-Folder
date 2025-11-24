#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={10,90,23,67};
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto it: v){
        pq.push(it);
    }
    int totalCost =0;
    while(pq.size()>1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int sum = a+b;
        totalCost+=sum;
        pq.push(sum);
    }
    cout<<"Minimum merge Cost: "<<totalCost<<"\n";
    return 0;
}