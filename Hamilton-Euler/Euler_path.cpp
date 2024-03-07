#include <iostream>
#include <vector>

using namespace std;

const int MAX = 110;

int deg[MAX][MAX];
int n, m;
vector<int> result;

void findEulerPath(int u) {
    for (int v = 0; v < n; v++) {
        if (deg[u][v] > 0) {
            deg[u][v]--;
            deg[v][u]--;
            
            findEulerPath(v);
        }
    }
    result.push_back(u);
}

int main() {
    cin >> n >> m;
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        deg[u][v]++;
        deg[v][u]++;
    }
    int u = -1, v = -1;
    bool bad = false;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += deg[i][j];
        }
        if (cnt % 2 == 1) {
            if (u == -1) {
                u = i;
            } else if ( v == -1) {
                v = i;
            } else {
                bad = true;
                break;
            }
        }
    }
    if (bad) {
        cout << "Graph does not have Euler Path";
        return 0;
    }
    if (u != -1) {
        deg[u][v] = deg[v][u] = 1;
        m++;
    }
    findEulerPath(0);
    if (result.size() != m + 1) {
        cout << "Graph does not have Euler Path";
        return 0;
    }
    if (u == -1) {
        cout << "Uuler cycle: ";
        for (int v : result) {
            cout << v << " ";
            return 0;
        }
    }
    for (int i = 0; i < result.size(); i++) {
        if ((result[i] == u && result[i + 1] == v) || (result[i] == v && result[i + 1] == u)) {
            for (int j = 1; j <= i; j++) {
                result.push_back(result[j]);
                result.erase(result.begin(), result.begin() + i + 1);
                break;
            }
        }
    }
    cout << "Euler Path: ";
    for (int v : result) {
        cout << v << " ";
    }
    return 0;
}
