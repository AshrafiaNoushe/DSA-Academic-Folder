#include <bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = v[i];
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
int main()
{
    vector<int> v = {70, 30, 50, 10};
    insertion_sort(v);
    for (auto it : v)
    {
        cout << it << " "; // not v[it], here it its element itself
    }
    return 0;
}