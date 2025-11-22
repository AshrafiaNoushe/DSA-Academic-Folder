#include<bits/stdc++.h>
using namespace std;
vector<int> jobSeq(vector<int>&profit, vector<int>&dead){ // i have to return a vector not int
    int n = profit.size();
    vector<pair<int,int>>jobs;
    for(int i =0;i<n;i++){
        jobs.push_back({profit[i],dead[i]});
    }
    int Ccount =0;
    int totalprofit =0;
    sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
    vector<int>slot(n,0);
    for(int i =0;i<n;i++){
        int start = min(n,jobs[i].second)-1;
        for(int j= start;j>=0;j--){
            if(slot[j]==0){
                slot[j]=1;
                Ccount++;
                totalprofit +=jobs[i].first;
                break; 
                /*
                Each job is scheduled only once.
                so if i don't use break then eida aro check debe but 
                i need onl the durer as same as deadline one slot 
                if its not empty then -- kore ager slot check debo. 
                eikhane amr ekta job er jnno ekta slot ey lagbe.
                */
            }
        }
    }
    return {totalprofit,Ccount};

}
int main()
{
    vector<int>profit = {100, 19, 27, 25, 15};
    vector<int>deadline={ 2, 1, 2, 1, 1};
    vector<int>ans = jobSeq(profit,deadline);
    cout<<"Total profit: "<<ans[0]<<" Deadline: "<<ans[1]<<"\n";
    return 0;
}