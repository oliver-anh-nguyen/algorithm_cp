//
//  main.cpp
//  NikhilAndCommand
//
//  Created by AnhNguyen on 21/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    string cmd, dir;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> paths = vector<string>();
        for (int i = 0; i < n; i++) {
            cin >> cmd;
            if (cmd == "pwd") {
                for (int j = 0; j < paths.size(); j++) {
                    cout << '/' << paths[j];
                }
                cout << '/' << '\n';
            } else {
                cin >> dir;
                if (dir[0] == '/') {
                    paths.clear();
                    dir = dir.substr(1);
                }
                stringstream inp(dir);
                string tmp;
                while(getline(inp, tmp, '/')) {
                    if (tmp == ".." && paths.size() > 0) {
                        paths.pop_back();
                    } else {
                        paths.push_back(tmp);
                    }
                }
            }
        }
    }
    return 0;
}
