//
//  main.cpp
//  EnduringExodus
//
//  Created by AnhNguyen on 29/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int S[10];
int pos[10];

bool valid(int n, string s, int k, int m) {
    for (int i = 1; i <= n ; i++) {
        if (s[i] == '0') {
            int val = S[min(n, i + m)] - S[max(0, i - m - 1)];
            if (val >= k + 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int empty = 0;
    for (int i = 1; i <= n; i++) {
        S[i] = S[i-1] + (s[i] == '0');
        if (s[i] == '0') {
            pos[S[i]] = i;
            empty++;
        }
    }
    
    int l = 0, r = n + 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (valid(n, s, k , m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << r + 1;
    return 0;
}
