#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    vector<pair<int, int>> activities;
    for (int i = 0; i < N; i++)
        activities.push_back({finish[i], start[i]});

    sort(activities.begin(), activities.end());

    int count = 1;
    int lastFinish = activities[0].first;

    cout << "Selected activities: ";
    cout << "(" << activities[0].second << ", " << activities[0].first << ") ";

    for (int i = 1; i < N; i++) {
        if (activities[i].second >= lastFinish) {
            cout << "(" << activities[i].second << ", " << activities[i].first << ") ";
            lastFinish = activities[i].first;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count;
    return 0;
}
