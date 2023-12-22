//
//  main.cpp
//  SashaAndBit
//
//  Created by AnhNguyen on 11/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 21);
int sumXor[2][N];
int n;

int main(){
    cin >> n;
    sumXor[0][0] = 1;
    int tmp = 0, x;
    long long res = 0;
    for (int i = 1; i <= n; i++){
        cin >> x;
        tmp = tmp ^ x;
        res += sumXor[i % 2][tmp];
        sumXor[i % 2][tmp]++;
    }
    cout << res;
    return 0;
}
