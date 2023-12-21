//
//  main.cpp
//  DIstance
//
//  Created by AnhNguyen on 01/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> countS(26, 0), countT(26, 0);
    string s, t;
    cin >> s >> t;
    for (auto c : s) {
        countS[c - 'a']++;
    }
    for (auto c : t) {
        countT[c - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += abs(countS[i] - countT[i]);
    }
    cout << res;
    return 0;
}
