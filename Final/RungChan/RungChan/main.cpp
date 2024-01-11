#include <iostream>
using namespace std;

int sumDigits(long long n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

bool isEarthquake(long long year, long long s) {
    return (year - sumDigits(year) >= s);
}

long long solve(long long L, long long R, long long s) {
    long long result = -1;

    while (L <= R) {
        long long mid = L + (R - L) / 2;

        if (isEarthquake(mid, s)) {
            result = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long L, R, s;
        cin >> L >> R >> s;

        long long ans = solve(L, R, s);

        cout << (ans == -1 ? 0 : R - ans + 1) << '\n';
    }

    return 0;
}
