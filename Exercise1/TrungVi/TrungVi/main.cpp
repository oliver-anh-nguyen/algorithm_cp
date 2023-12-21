//
//  main.cpp
//  TrungVi
//
//  Created by AnhNguyen on 02/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& v) {
    sort(v.begin(), v.end());
    return v[v.size()/2];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector<int>medians;
    for (int i = 0; i < n; i++) {
        medians.push_back(solve(v[i]));
    }
    cout << solve(medians);
    return 0;
}
