//
//  main.cpp
//  Rotate
//
//  Created by AnhNguyen on 23/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string a[55];
int n, k;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool checkWinning(int x, int y) {
    if (a[x][y] == '.') {
        return false;
    }
    int vert, horz, diag1, diag2;
    vert = horz = diag1 = diag2 = 1;
    for (int i = 1; i < k; i++) {
        if (isValid(x, y + i) && a[x][y + i] == a[x][y]) horz++;
        if (isValid(x + i, y) && a[x + i][y] == a[x][y]) vert++;
        if (isValid(x + i, y - i) && a[x + i][y - i] == a[x][y]) diag1++;
        if (isValid(x + i, y + i) && a[x + i][y + i] == a[x][y]) diag2++;
    }
    return (vert == k || horz == k || diag1 == k || diag2 == k);
}

void solve() {
    string ans[] = {"Neither", "Red", "Blue", "Both"};
    int index = 0;
    bool red, blue;
    red = blue = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (checkWinning(i, j)) {
                if (a[i][j] == 'R') red = true;
                if (a[i][j] == 'B') blue = true;
            }
        }
    }
    if (red) index++;
    if (blue) index+=2;
    cout << ans[index] << '\n';
}

void rotate() {
    for (int i = 0; i < n; i++) {
        int pos = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] != '.') {
                swap(a[i][j], a[i][pos]);
                pos--;
            }
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Case #" << t << ": ";
        rotate();
        solve();
    }
    return 0;
}
