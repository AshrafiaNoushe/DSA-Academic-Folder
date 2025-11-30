#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

//IT
// void quickSortIterative(vector<int>& a) {
//      stack<pair<int,int>> st;
//     st.push({0, a.size() - 1});

//     while (!st.empty()) {
//         auto [low, high] = st.top();
//         st.pop();

//         if (low < high) {
//             int pi = partition(a, low, high);

//             st.push({low, pi - 1});
//             st.push({pi + 1, high});
//         }
//     }
// }

int main()
{

}