//
//  main.cpp
//  BullEye
//
//  Created by AnhNguyen on 02/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long f(long long r, long long n) {
    return 2 * r + 2 * n - 1;
}

int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        long long r, t;
        cin >> r >> t;
        long long l = 0;
        long long right = min((long long)(2e9), t);
        long long res;
        while (l <= right) {
            long long m = l + (right - l)/2;
            if (f(r, m) <= t / m) {
                res = m;
                l = m + 1;
            } else {
                right = m - 1;
            }
        }
        cout << "Case #" << i << ": " << res << '\n';
    }
    return 0;
}
