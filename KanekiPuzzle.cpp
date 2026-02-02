#include <iostream>
using namespace std;

long long fit(long long s, long long n, long long h, long long w) {
    long long r1 = s / h;
    long long c1 = s / w;
    if (r1 > 0 && c1 > 0 && r1 * c1 >= n) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, h, w;
        cin >> n >> h >> w;

        long long lo = 1, hi = 1;

        while (!fit(hi, n, h, w)) hi *= 2;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (fit(mid, n, h, w)) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << "\n";
    }

    return 0;
}
