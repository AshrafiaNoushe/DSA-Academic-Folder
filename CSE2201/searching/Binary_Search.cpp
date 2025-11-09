#include <bits/stdc++.h>
using namespace std;
int Binary_search(vector<int> &v, int low, int high, int item)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == item)
        {
            return mid;
        }
        else if (v[mid] > item)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int item;
    cin >> item;
    int l = 0;
    int index = Binary_search(v, l, n - 1, item);
    if (index != -1)
    {
        cout << "Found at: " << index << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
    return 0;
}