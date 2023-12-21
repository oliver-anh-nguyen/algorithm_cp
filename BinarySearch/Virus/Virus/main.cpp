//
//  main.cpp
//  Virus
//
//  Created by AnhNguyen on 25/11/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> viruses, badVirueses;

bool containBadVirus(string virus, string badVirus) {
    bool contain = true;
    int virusLength = virus.length();
    int badVirusLength = badVirus.length();
    for (int i = 0; i < virusLength - badVirusLength + 1; i++) {
        contain = true;
        for (int j = 0; j < badVirusLength; j++) {
            if (virus[i + j] != badVirus[j] && badVirus[j] != '*') {
                contain = false;
                break;
            }
        }
        if (contain) {
            return true;
        }
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        badVirueses = vector<string>(n);
        for (int i = 0; i < n; i++) {
            cin >> badVirueses[i];
        }
        cin >> m;
        viruses = vector<string>(m);
        for (int i = 0; i < m; i++) {
            cin >> viruses[i];
        }
        cout << "Data set #" << t << ":" << '\n';
        for (int i = 0; i < m; i++) {
            bool isValid = false;
            cout << "Virus #" << i + 1 << ": ";
            for (int j = 0; j < n; j++) {
                if (containBadVirus(viruses[i], badVirueses[j])) {
                    cout << "Nuts. This virus is illegal in Hawaii!\n";
                    isValid = true;
                    break;
                }
            }
            if (!isValid) {
                cout << "Cool! Victor can take it with him!\n";
            }
        }
        cout << '\n';
    }
    return 0;
}
