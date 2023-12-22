//
//  main.cpp
//  CollegeAdmission
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
    
    stack<int> s;
    vector<bool> checked(n+1, false);
    int highest = 0;
    while(n--) {
        int x;
        cin >> x;
        if (x > highest) {
            cout << x << ' ';
            highest++;
            while(highest < x) {
                s.push(highest);
                highest++;
            }
        }
        checked[x] = true;
        while(!s.empty() && checked[s.top()]) {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    cout << '\n';
    return 0;
}
