//
//  main.cpp
//  NewYear
//
//  Created by AnhNguyen on 12/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    if (k == 1){
        cout << n << "\n";
        return 0;
    }
    long long res = 0;
    while (n > 0) {
        n = n >> 1;
        res = res << 1 | 1;
    }
    cout << res;
}
