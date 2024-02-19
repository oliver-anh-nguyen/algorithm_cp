#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Application {
    int emp1, emp2, cost;
};

bool compareApplications(const Application& a, const Application& b) {
    return a.cost < b.cost;
};

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
        }
    }
    
    int findSet(int u) {
        if (u != parent[u]) {
            parent[u] = findSet(parent[u]);
        }
        return parent[u];
    }
    
    void unionSets(int u, int v) {
        int pu = findSet(u);
        int pv = findSet(v);
        if (pu == pv) return;
        parent[pv] = pu;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> qualifications(n);
    for(int i = 0; i < n; i++) {
        cin >> qualifications[i];
    }
    
    int m;
    cin >> m;
    
    vector<Application> apps(m);
    for (int i = 0; i < m; i++) {
        int app1, app2, cost;
        cin >> app1 >> app2 >> cost;
        if (qualifications[app1 - 1] > qualifications[app2 - 1]) {
            apps[i].emp1 = app1;
            apps[i].emp2 = app2;
            apps[i].cost = cost;
        }
    }
    
    sort(apps.begin(), apps.end(), compareApplications);
    
    DSU ds(n);

    int totalCost = 0;
    int edgesAdded = 0;
    
    for (const Application& app : apps) {
        if (ds.findSet(app.emp1) != ds.findSet(app.emp2) && ds.findSet(app.emp2) == app.emp2) {
            ds.unionSets(app.emp1, app.emp2);
            totalCost += app.cost;
            edgesAdded++;
            
            if (edgesAdded == n - 1) {
                break;
            }
        }
    }
    
    if (edgesAdded == n - 1) {
        cout << totalCost << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
