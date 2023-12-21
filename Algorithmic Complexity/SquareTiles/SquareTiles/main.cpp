//
//  main.cpp
//  SquareTiles
//
//  Created by AnhNguyen on 23/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int r, c;
string a[60];

void solve() {
    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            if (a[i][j] == '#' && a[i][j+1] == '#' && a[i + 1][j] == '#' && a[i + 1][j + 1] == '#') {
                a[i][j] = '/';
                a[i][j + 1] = 92;
                a[i + 1][j] = 92;
                a[i + 1][j + 1] = '/';
            }
        }
    }
}

void output() {
    bool check = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '#') {
                check = false;
            }
        }
    }
    if (!check) {
        cout << "Impossible" << '\n';
    } else {
        for (int i = 0; i < r; i++) {
            cout << a[i] << '\n';
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            cin >> a[i];
        }
        solve();
        cout << "Case #" << t << ":" << '\n';
        output();
    }
}
