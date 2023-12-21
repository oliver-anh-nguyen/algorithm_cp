//
//  main.cpp
//  Multitasking
//
//  Created by AnhNguyen on 13/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

bool solve(bitset<N>&cal, int start, int ending) {
    for(int i = start; i < ending && i < N; i++){
        if(cal[i]) return true;
        else cal[i] = true;
    }
    return false;
}

int main() {
    int n, m, s, e, c;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        bitset<N> cal;
        bool isConflict = false;
        while (n--) {
            cin >> s >> e;
            if(!isConflict) isConflict = solve(cal,s,e);
        }
        while (m--) {
            cin >> s >> e >> c;
            while(!isConflict && s < N){
                isConflict = solve(cal,s,e);
                s += c;
                e += c;
            }
        }
        cout << (isConflict ? "CONFLICT" : "NO CONFLICT") << '\n';
    }
}
