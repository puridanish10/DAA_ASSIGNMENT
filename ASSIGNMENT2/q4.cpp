#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int N = 5;
    vector<Job> jobs = {
        {'J1', 2, 100},
        {'J2', 1, 19},
        {'J3', 2, 27},
        {'J4', 1, 25},
        {'J5', 3, 15}
    };

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<char> slot(maxDeadline, '-');
    int totalProfit = 0;

    for (auto job : jobs) {
        for (int j = job.deadline - 1; j >= 0; j--) {
            if (slot[j] == '-') {
                slot[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (char c : slot)
        if (c != '-') cout << c << " ";

    cout << "\nMaximum Profit = " << totalProfit;
    return 0;
}
