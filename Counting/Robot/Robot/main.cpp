//
//  main.cpp
//  Robot
//
//  Created by AnhNguyen on 09/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Segment {
    int x, y;
} a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, L, R;
    vector<int> pos;
    cin >> n >> L >> R;
    pos.push_back(L);
    pos.push_back(R);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        pos.push_back(a[i].x);
        pos.push_back(a[i].y);
    }
    sort(pos.begin(), pos.end());
    // pos : 1 1 3 5 5 8 8 8 10 12
    map<int, int> id;
    for(int i = 0; i < pos.size(); i++) {
        id[pos[i]] = i;
    }
    // id : [1:1], [3:2], [5:4], [8:7], [10:8], [12:9]
    vector<int> count(pos.size() + 1, 0);
    for (int i = 1; i <= n; i++) {
        count[id[a[i].x]]++;
        count[id[a[i].y] + 1]--;
    }
    // count : 0, 1, 1, 0, 1, -1, 0, 1, -2, 0, -1
    for (int i = 1; i < pos.size(); i++)
        count[i] += count[i - 1];
    // count : 0, 1, 2, 2, 3, 2, 2, 3, 1, 1, -1
    vector<int> pos1;
    for (int i = id[L]; i <= id[R]; i++) {
        if (count[i] == 1)
            pos1.push_back(i);
    }
    // pos1: 1, 8
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int left = lower_bound(pos1.begin(), pos1.end(), id[a[i].x]) - pos1.begin();
        int right = upper_bound(pos1.begin(), pos1.end(), id[a[i].y]) - pos1.begin() - 1;
        
        if (right - left + 1 > 0) continue;
        
        res = max(res, a[i].y - a[i].x);
    }
    
    cout << res << '\n';
    return 0;
}
