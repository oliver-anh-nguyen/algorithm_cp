#include <iostream>

using namespace std;

int digitSum(long long n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

long long calculateDigitSum(long long x) {
    if (x <= 0) {
        return 0;
    }
    if (x % 10 == 9) {
        return 10 * calculateDigitSum(x/10) + 45 * (x / 10 + 1);
    }
    return calculateDigitSum(x - 1) + digitSum(x);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << calculateDigitSum(b) - calculateDigitSum(a-1) << '\n';
    }

    return 0;
}
