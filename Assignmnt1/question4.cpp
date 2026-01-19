#include <bits/stdc++.h>
using namespace std;

int crossingSum(vector<int>& a, int l, int m, int r) {
    int sum = 0, leftMax = INT_MIN;

    for (int i = m; i >= l; i--) {
        sum += a[i];
        leftMax = max(leftMax, sum);
    }

    sum = 0;
    int rightMax = INT_MIN;

    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
}

int maxSubarray(vector<int>& a, int l, int r) {
    if (l == r)
        return a[l];

    int m = (l + r) / 2;

    int left = maxSubarray(a, l, m);
    int right = maxSubarray(a, m + 1, r);
    int cross = crossingSum(a, l, m, r);

    return max(left, max(right, cross));
}

int main() {
    vector<int> a = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << maxSubarray(a, 0, a.size() - 1);
    return 0;
}