#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int n, m;
vector<int> path;
vector<bool> visited;

void findHamiltonPath(int u) {
    if (path.size() == n) {
        bool hasCycle = false;
        for (int v : graph[u]) {
            if (v == path[0]) {
                hasCycle = false;
                break;
            }
        }
        if (hasCycle) {
            cout << "Found a Hamilton cycle";
        } else {
            cout << "Found a Hamilton path";
        }
    }
    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            path.push_back(v);
            findHamiltonPath(v);
            path.pop_back();
            visited[v] = false;
        }
    }
}

