#include <bits/stdc++.h>
using namespace std;

// Function to find max crossing sum
int maxCrossSum(vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= left; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid+1; i <= right; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

// Divide and conquer function
int maxSubArraySum(vector<int>& arr, int left, int right) {
    if(left == right) // Base case: only one element
        return arr[left];

    int mid = (left + right) / 2;

    int left_max = maxSubArraySum(arr, left, mid);
    int right_max = maxSubArraySum(arr, mid+1, right);
    int cross_max = maxCrossSum(arr, left, mid, right);

    return max({left_max, right_max, cross_max});
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    cout << "Maximum Subarray Sum: " << maxSubArraySum(arr, 0, n-1) << endl;
}
