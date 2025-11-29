#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;   // sort by ratio descending
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto &item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            totalValue += item.value;
            W -= item.weight;
        }
        else {
            // take fraction
            totalValue += (double)item.value * ((double)W / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items = { {10, 60}, {20, 100}, {30, 120} };
    int W = 50;

    cout << "Fractional Knapsack Max Value = "
         << fractionalKnapsack(W, items) << endl;
}
