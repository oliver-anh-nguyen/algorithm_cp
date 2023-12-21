//
//  main.cpp
//  MuaBi
//
//  Created by AnhNguyen on 25/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Marbles {
    int a, b;
};

bool option(const Marbles &a, const Marbles &b) {
    return a.b > b.b;
}

int n, m;
vector<Marbles> box;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        Marbles tmp;
        cin >> tmp.a >> tmp.b;
        box.push_back(tmp);
    }
    sort(box.begin(), box.end(), option);
    
    int res = 0;
    int boxes = 0;
    
    for (int i = 0; i < m; i++) {
        if (boxes + box[i].a <= n) {
            boxes += box[i].a;
            res += box[i].a * box[i].b;
        } else {
            int left = n - boxes;
            res += box[i].b * left;
            break;
        }
    }
    cout << res;
    return 0;
}
