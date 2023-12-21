//
//  main.cpp
//  SudhanvaBooks
//
//  Created by AnhNguyen on 21/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    stack<int> s;
    while (tc--) {
        int t, n;
        cin >> t;
        if (t == 1) {
            cin >> n;
            s.push(n);
        } else {
            if (s.empty()) {
                cout << "kuchbhi?" << '\n';
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
    }
    return 0;
}
