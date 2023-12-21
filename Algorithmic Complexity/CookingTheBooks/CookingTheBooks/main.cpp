//
//  main.cpp
//  CookingTheBooks
//
//  Created by AnhNguyen on 18/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// "939214502", "9990999"

string solve(string str, bool max) {
    for (int s = 0; s < str.length() - 1; s++) {
        int r = s;
        for (int i = str.length() - 1; i >= s + 1; i--) {
            if (s == 0 && str[i] == '0') {
                continue;
            }
            
            if ((!max && str[i] < str[r]) || (max && str[i] > str[r])) {
                r = i;
            }
        }
        
        if (r != s) {
            char tmp = str[s];
            str[s] = str[r];
            str[r] = tmp;
            break;
        }
    }
    return str;
}

int main() {
    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        string a;
        cin >> a;
        cout << "Case #" << t << ": " << solve(a, false) << " " << solve(a, true) << endl;
    }
}
