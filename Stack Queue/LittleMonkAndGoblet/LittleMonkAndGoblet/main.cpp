//
//  main.cpp
//  LittleMonkAndGoblet
//
//  Created by AnhNguyen on 21/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    queue<int> q[5];
    while(n--) {
        char t;
        int x, y;
        cin >> t;
        if (t == 'E') {
            cin >> x >> y;
            if(q[x].empty()) {
                q[0].push(x);
            }
            q[x].push(y);
        } else {
            x = q[0].front();
            y = q[x].front();
            cout << x << ' ' << y << '\n';
            q[x].pop();
            if (q[x].empty()) {
                q[0].pop();
            }
        }
    }
    return 0;
}
