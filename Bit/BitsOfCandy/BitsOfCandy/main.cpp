//
//  main.cpp
//  BitsOfCandy
//
//  Created by AnhNguyen on 10/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const string candyNames[16] = {
    "Unknown candy bar!",    // 0000
    "Planters",                // 0001
    "Reeses_Pieces",        // 0010
    "Unknown candy bar!",    // 0011
    "Sugar_Babies",            // 0100
    "Pay_Day",                // 0101
    "Unknown candy bar!",    // 0110
    "Unknown candy bar!",    // 0111
    "Hersheys",                // 1000
    "Goobers",                // 1001
    "Reeses_Cups",            // 1010
    "Nutrageous",            // 1011
    "Caramello",            // 1100
    "Baby_Ruth",            // 1101
    "Milky_Way",            // 1110
    "Snickers"                // 1111
};

int getVal(string str) {
    bool check = false;
    int index = 0;
    while (str[index] == '~') {
        check = !check;
        index++;
    }
    str.erase(0, index);
    int ans = 0;
    for (int i = 0; i < 16; i++) {
        if (str == candyNames[i]) {
            ans = i;
            break;
        }
    }
    if (check) {
        ans = ~ans;
    }
    return (ans & 15);
}

void solve() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string str;
    vector<int> val;
    while (ss >> str) {
        if (str == "&") {
            val.push_back(-2);
        } else if (str == "|") {
            val.push_back(-1);
        } else {
            val.push_back(getVal(str));
        }
    }
    for (int k = -2; k <= -1; k++) {
        vector<int> tmp;
        for (int i = 0; i < (int)val.size(); i++) {
            if (val[i] == k){
                if (k == -2) tmp.back() &= val[i + 1];
                else tmp.back() |= val[i + 1]; // 1001 |= 0101
                i++;
            } else {
                tmp.push_back(val[i]);
            }
        }
        swap(val, tmp);
    }
    cout << candyNames[val[0]] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        solve();
    }
    return 0;
}
