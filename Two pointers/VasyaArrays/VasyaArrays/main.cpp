//
//  main.cpp
//  VasyaArrays
//
//  Created by AnhNguyen on 20/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 3*100000 + 5;
int a[N], b[N];
int n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int j = 0; j < m; j++) cin >> b[j];
    
    long long s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    for (int j = 0; j < m; j++) s -= b[j];
    if (s  != 0) {
        cout << -1 << '\n';
        return 0;
    }
    
    int pa = 0, pb = 0;
    int ans = 0;
    while (pa < n) {
        ans++;
        long long suma = a[pa++], sumb = b[pb++];
        
        while(suma != sumb) {
            if (suma < sumb) {
                suma += a[pa++];
            } else {
                sumb += b[pb++];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
