//
//  main.cpp
//  Mice
//
//  Created by AnhNguyen on 19/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    int cnt = 0, j = 0, l = -1;
    for (int i = 0; i < n; i++) {
        while (j < m && abs(a[i] - b[j+1]) < abs(a[i] - b[j])) {
            j++;
        }
        if (l < j || (i > 0 && abs(a[i-1] - b[j]) == abs(a[i] - b[j]))) {
            cnt++;
            l = j;
        } else if (j < m && abs(a[i] - b[j+1]) == abs(a[i] - b[j])) {
            cnt++;
            l = ++j;
        }
    }
    cout << n - cnt;
    return 0;
}
