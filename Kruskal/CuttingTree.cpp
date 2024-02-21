#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

struct DSU {
    DSU() {
    }
    
    int findSet(int u) {
        while (u != 0) {
            if (parent[u] == 0) {
                break;
            } else {
                u = parent[u];
            }
        }
        return u;
    }
};

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        cin >> n >> k;

        parent = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> parent[i];
        }
        
        DSU ds;
        cout << "Case #" << t << ":\n";

        for (int i = 0; i < k; ++i) {
            char type;
            cin >> type;
            
            if (type == 'C') {
                int x;
                cin >> x;
                // Remove the edge
                parent[x] = 0;
            } else if (type == 'Q') {
                int a, b;
                cin >> a >> b;
                // Check if there is a path between a and b
                if (ds.findSet(a) == ds.findSet(b)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
