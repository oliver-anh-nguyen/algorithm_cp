//
//  main.cpp
//  KB
//
//  Created by AnhNguyen on 02/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n > 26) {
        cout << -1;
        return 0;
    }
    int cnt[26] = {0};
    for (int i = 0; i  < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            res += cnt[i] - 1;
        }
    }
    cout << res << '\n';
}
