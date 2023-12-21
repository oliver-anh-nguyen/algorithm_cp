//
//  main.cpp
//  BinhPhuong
//
//  Created by AnhNguyen on 26/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

bool isValid(long long x, long long k){
    long long index = 0;
    for (long long i = 1; (i * i < x && i <= 1e6); i++){
        long long y = sqrt(x - i * i);
        index += y;
    }
    return index < k;
}

long long findNumber(long long k){
    long long res = 0, l = 0, r = INF;
    while (l <= r){
        long long mid = (l + r) / 2;
        if (isValid(mid, k)){
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return res;
}

int main(){
    int id;
    long long k;
    
    cin >> id;
    cin >> k;
    cout << findNumber(k) + 1 << '\n';
}
