#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> a;

bool canSplit(int x) {
    int segments = 1;
    int current = 0;
    for (int i = 0; i < n; i++) {
        if ((current | a[i]) <= x) {
            current |= a[i];
        }
        else {
            segments++;
            current = a[i];
            if (segments > m)
                return false;
        }
    }
    return true;
}

int main() {
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter number of partitions: ";
    cin >> m;

    a.resize(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = 0;

    for (int bits = 30; bits >= 0; bits--) {
        int tryValue = result | (1 << bits);
        if (canSplit(tryValue)) {
            result = tryValue;
        }
    }

    cout << "The minimum value that can split the array into " << m << " or fewer segments is: " << result << endl;

    return 0;
}
