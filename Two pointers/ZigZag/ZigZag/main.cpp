//
//  main.cpp
//  ZigZag
//
//  Created by AnhNguyen on 20/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int t, n, a[N];
int cntl[N], cntr[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cntl[i] = cntr[i] = 0;
        }
        long long int ans = 0;
        for (int j = 1; j <= n; ++j){
            memset(cntr, 0, sizeof(cntr));
            for(int k = n; k >= j+1; --k){
                ans += cntl[a[k]] * cntr[a[j]];
                cntr[a[k]]++;
            }
            cntl[a[j]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
