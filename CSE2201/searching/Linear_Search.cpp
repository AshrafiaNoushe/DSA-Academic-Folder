#include <bits/stdc++.h>
using namespace std;
int Linera_search(int arr[], int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[10]; // size count 1 theke but index 0;
    int n;
    cin >> n;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> item;
    int index = Linera_search(arr, n, item);
    if (index == -1)
    {
        cout << "Item not found" << "\n";
    }
    else
    {
        cout << "Item found at: " << index << "\n";
    }
    return 0;
}