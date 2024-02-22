#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> res;
        res.resize(32, -1);
        
        for(int i = 0; i < n; i++) {
            string q;
            int a, b;
            
            cin >> q;
            if (q == "SET") {
                cin >> a;
                res[a] = 1;
            }
            if (q == "CLEAR") {
                cin >> a;
                res[a] = 0;
            }
            if (q == "AND") {
                cin >> a >> b;
                if (res[a] == 1 && res[b] == 1) {
                    res[a] = 1;
                } else if (res[a] == 0 || res[b] == 0) {
                    res[a] = 0;
                } else {
                    res[a] = -1;
                }
            }
            if (q == "OR") {
                cin >> a >> b;
                if (res[a] == 1 || res[b] == 1) {
                    res[a] = 1;
                } else if (res[a] == 0 && res[b] == 0) {
                    res[a] = 0;
                } else {
                    res[a] = -1;
                }
            }
        }
        reverse(res.begin(), res.end());
        for (auto i : res) {
            if (i == -1) {
                cout << "?";
            } else {
                cout << i;
            }
        }
        cout << '\n';
    }
    return 0;
}
