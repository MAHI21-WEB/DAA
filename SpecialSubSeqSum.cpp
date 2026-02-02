#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long *a = new long long[n];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < k; i++) {
        int mx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[mx]) mx = j;
        }
        long long t = a[i];
        a[i] = a[mx];
        a[mx] = t;
    }

    long long top = 0;
    for (int i = 0; i < k; i++) top += a[i];

    cout << sum - top << "\n";

    delete[] a;
    return 0;
}
