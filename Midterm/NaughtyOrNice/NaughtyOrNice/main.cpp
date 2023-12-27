//
//  main.cpp
//  NaughtyOrNice
//
//  Created by AnhNguyen on 26/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int h, d;
        cin >> h >> d;
        vector<int> cnt(h, 0);
        vector<vector<vector<int>>> sweep(11, vector<vector<int>>(11));
        for (int i = 2; i <= 10; i++) {
            for (int r = 0; r <= 10; r++) {
                sweep[i][r] = vector<int>(h / i + 1);
            }
        }
        while (d--) {
            int s, k, p;
            cin >> s >> k >> p;
            s--;
            int r = s % k;
            int L = s / k;
            int R = L + p - 1;
            sweep[k][r][L] += 1;
            if (R + 1 < sweep[k][r].size()) {
                sweep[k][r][R + 1] -= 1;
            }
        }
        for (int k = 2; k <= 10; k++) {
            for (int r = 0; r <= k - 1; r++) {
                int cur = 0;
                for (int i = 0; i < sweep[k][r].size(); i++) {
                    cur += sweep[k][r][i];
                    if (i * k + r < h) {
                        cnt[i * k + r] += cur;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < h; i++) {
            if (cnt[i] > cnt[ans]) {
                ans = i;
            }
        }
        cout << "House " << ans + 1 << " should get the biggest and best gift next Christmas.\n";
    }
    return 0;
}
