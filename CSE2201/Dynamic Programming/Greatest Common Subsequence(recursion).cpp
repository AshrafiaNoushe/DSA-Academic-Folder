#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0; // if ekta empty hoye jai
    else if (s1[m - 1] == s2[n - 1])
    { // if match
        return 1 + LCS(s1, s2, m - 1, n - 1);
    }
    else
    {
        return max(LCS(s1, s2, m - 1, n), LCS(s1, s2, m, n - 1));
    }
}
int main()
{
    string S1;
    string S2;
    cin >> S1 >> S2;
    int m = S1.size();
    int n = S2.size();
    cout << "Longest common seq: " << LCS(S1, S2, m, n) << "\n";
    return 0;
}
/*
input:
ABCBDAB 
BDCABA
output:
4
*/