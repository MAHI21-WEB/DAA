#include <iostream>
using namespace std;

int main() {
    int n, h, w;
    cin >> n >> h >> w;

    int low = 0;
    int high = n * (h > w ? h : w);
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        int fitH = mid / h;
        int fitW = mid / w;

        if (fitH * fitW >= n) {
            ans = mid;                  high = mid - 1;   // try smaller
        } else {
            low = mid + 1;    // need bigger size
        }
    }

    cout << ans << endl;

    return 0;
}


