#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Company {
    int u, v, f;
};


struct DSU {
    vector<int> parent, ranks;
    
    DSU(int n) {
        parent.resize(n + 1);
        ranks.resize(n + 1, 1);
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
        if (ranks[pu] > ranks[pv]) {
            parent[pv] = pu;
        } else if (ranks[pu] < ranks[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            ranks[pu]++;
        }
    }
};

bool compareCompanies(const Company& a, const Company& b) {
    return a.f > b.f;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int n, m;
        cin >> n >> m;

        vector<Company> companies(m);
        for (int i = 0; i < m; ++i) {
            cin >> companies[i].u >> companies[i].v >> companies[i].f;
        }

        sort(companies.begin(), companies.end(), compareCompanies);

        DSU ds(n);

        int minCompanies = 0;
        long long maxFitness = 0;

        for (const Company& company : companies) {
            if (ds.findSet(company.u) != ds.findSet(company.v)) {
                ds.unionSets(company.u, company.v);
                minCompanies++;
                maxFitness += company.f;
            }
        }

        cout << "Case " << tc << ": " << minCompanies << " " << maxFitness << '\n';
    }

    return 0;
}
