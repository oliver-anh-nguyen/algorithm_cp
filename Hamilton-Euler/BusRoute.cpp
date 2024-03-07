#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;

int deg[MAX][MAX];
vector<int> euler;
vector<int> graph[MAX];

void dfs(int s) {
    for (auto c : graph[s]) {
        if (deg[s][c]) {
            deg[s][c]--;
            dfs(c);
        }
    }
    euler.push_back(s);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<int> bus(m + 1);
        for (auto& x : bus) cin >> x;
        for (int i = 1; i < m + 1; i++) {
            deg[bus[i-1]][bus[i]]++;
            graph[bus[i-1]].push_back(bus[i]);
        }
    }
    dfs(1);
    reverse(euler.begin(), euler.end());
    cout << euler.size() - 1 << ' ';
    for (auto c : euler) {
        cout << c << ' ';
    }
    return 0;
}
