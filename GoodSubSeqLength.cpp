#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1;

    for (int i = 0; i < n; i++) {
        int mn = a[i], mx = a[i];
        int j = i;

        while (j < n) {
            if (a[j] < mn) mn = a[j];
            if (a[j] > mx) mx = a[j];

            if (mx - mn > 10) break;

            int len = j - i + 1;
            if (len > ans) ans = len;

            j++;
        }
    }

    cout << ans << "\n";

    delete[] a;
    return 0;
}
