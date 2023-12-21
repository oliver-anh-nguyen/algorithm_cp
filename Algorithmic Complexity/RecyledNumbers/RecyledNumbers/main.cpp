//
//  main.cpp
//  RecyledNumbers
//
//  Created by AnhNguyen on 18/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
    if (a < 10) {
        return 0;
    }
    int ans = 0;
    int power = 1, tmp = a;
    while (tmp >= 10) {
        power *= 10;
        tmp /= 10;
    }
    for (int i = a; i <= b; i++) {
        int j = i;
        do {
            j = (j / 10) + (j % 10) * power;
            if (j > i && j <= b) {
                ans += 1;
            }
        } while (j != i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << t << ": " << solve(a, b) << endl;
    }
}
