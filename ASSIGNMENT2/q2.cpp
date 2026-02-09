#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 5;
    int arrival[] = {900, 910, 920, 1100, 1120};
    int departure[] = {940, 1200, 950, 1130, 1140};

    sort(arrival, arrival + N);
    sort(departure, departure + N);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < N && j < N) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    cout << "Minimum number of platforms required = " << maxPlatforms;
    return 0;
}
