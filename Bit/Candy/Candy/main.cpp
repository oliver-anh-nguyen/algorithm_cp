//
//  main.cpp
//  Candy
//
//  Created by AnhNguyen on 10/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        int sum = 0;
        int sum_xor = 0;
        int min_c = 1e6;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            sum += c;
            sum_xor ^= c;
            min_c = min(min_c, c);
        }
        if (sum_xor == 0) cout << sum - min_c << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
