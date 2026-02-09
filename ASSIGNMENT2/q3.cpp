#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int N = 3, W = 50;
    vector<Item> items = {{100, 20}, {60, 10}, {120, 40}};

    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (int i = 0; i < N; i++) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    cout << "Maximum value = " << maxValue;
    return 0;
}
