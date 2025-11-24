//tabulation Bottom-Up approch
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S1 = "ABCBDAB";
    string S2 = "BDCABA";
    int m = S1.size();
    int n = S2.size();
    int mat[m+1][n+1]; //m>n here 1 col 1 row extra needed for 0 val
    for(int i=0;i<=m;i++){
        mat[i][0] =0;//1st col all ele =0
    }
    for(int j=0; j<=n;j++){
        mat[0][j] =0; //1st row all ele =0
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(S1[i-1]==S2[j-1]){
                mat[i][j] = 1+ mat[i-1][j-1];
            }else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    cout<<"Longest common subseq: "<<mat[m][n]<<"\n"; //last box'e ans pabo
    string len="";
    int i =m;
    int j=n;
    while(i>0 && j>0){
        if(S1[i-1]==S2[j-1]){
            len+=S1[i-1];
            i--;
            j--;
        }else if(mat[i-1][j]>mat[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(len.begin(),len.end());
    cout<<len<<endl;

}