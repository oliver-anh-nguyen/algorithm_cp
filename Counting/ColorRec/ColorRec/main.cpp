//
//  main.cpp
//  ColorRec
//
//  Created by AnhNguyen on 10/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int color[405][405];
int cnt[5][5];

int main() {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        color[x + N][y + N] = c;
    }
    int ans = 0;
    for (int x1 = -200; x1 <= 200; x1++) {
        for (int x2 = x1 + 1; x2 <= 200; x2++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cnt[i][j] = 0;
                }
            }
            
            for (int y = -200; y <= 200; y++) {
                int c1 = color[x1 + N][y + N];
                int c2 = color[x2 + N][y + N];
                cnt[c1][c2]++;
            }
            
            for (int c1 = 1; c1 <= 4; c1++) {
                for (int c2 = 1; c2 <= 4; c2++) {
                    if (c1 != c2) {
                        for (int c3 = 1; c3 <= 4; c3++) {
                            if (c3 != c1 && c3 != c2) {
                                int c4 = 10 - c1 - c2 - c3;
                                ans += cnt[c1][c2] * cnt[c3][c4];
                            }
                        }
                    }
                }
            }
        }
    }
    ans /= 2;
    cout << ans << '\n';
    return 0;
}
