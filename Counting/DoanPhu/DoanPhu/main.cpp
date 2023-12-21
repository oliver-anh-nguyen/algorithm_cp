//
//  main.cpp
//  DoanPhu
//
//  Created by AnhNguyen on 09/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int N = 1000;
    int a[N], b[N];
    int count[N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j < b[i]; j++) {
            count[j]++;
        }
    }
    int maxPasses = -1;
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        if (count[i] > maxPasses) {
            maxPasses = count[i];
            ans = 1;
        } else if (count[i] == maxPasses) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
