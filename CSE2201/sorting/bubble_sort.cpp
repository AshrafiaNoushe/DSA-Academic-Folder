#include <bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int> &v, int n)
{
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        isSwap = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j + 1], v[j]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            break;
        }
    }
}
int main()
{
    vector<int> v = {70, 30, 50, 10};
    int n = v.size();
    bubble_sort(v, n); // pass h = size -1
    for (auto it : v)
    {
        cout << it << " "; // not v[it], here it its element itself
    }
    return 0;
}