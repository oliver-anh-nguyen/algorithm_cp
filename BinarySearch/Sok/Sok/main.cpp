//
//  main.cpp
//  Sok
//
//  Created by AnhNguyen on 26/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValid(long long num) {
    return (num % 3 == 0) || (num % 5 == 0) || (num % 7 == 0);
}

long long findIndex(long long n) {
    long long res = n / 3 + n / 5 + n / 7;
    res -= n / 15 + n / 21 + n / 35;
    res += n / 105;
    return res;
}

long long solve(long long k) {
    long long l = 3;
    long long r = 1e16;
    while (l <= r) {
        long long m = (l + r) / 2;
        long long index = findIndex(m);
        if (index == k && isValid(m)){
            return m;
        }
        if (index < k){
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int tc;
    long long k;
    cin >> tc;
    cin >> k;
    cout << solve(k) << '\n';
    return 0;
}
