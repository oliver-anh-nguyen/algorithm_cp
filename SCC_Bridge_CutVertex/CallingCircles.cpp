#include <iostream>
#include <stack>
#include <map>

using namespace std;

const int MAX = 30;
vector<int> graph[MAX];
vector<int> low, num;
vector<bool> found;
stack<int> st;
int n, m, counter, c;
vector<int> ans[MAX];

void dfs(int u) {
    counter++;
    num[u] = low[u] = counter;
    st.push(u);
    for (int v : graph[u]) {
        if (found[v]) {
            continue;
        }
        if (num[v] > 0) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    
    if (num[u] == low[u]) {
        c++;
        int v;
        do {
            v = st.top();
            st.pop();
            ans[c].push_back(v);
            found[v] = true;
        } while(v != u);
    }
}

void solve() {
    counter = 0;
    c = 0;
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    found.assign(n + 1, false);
    st = stack<int>();
    
    map<string, int> id;
    map<int, string> name;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        string u, v;
        cin >> u >> v;
        if (!id[u]) {
            cnt++;
            id[u] = cnt;
            name[cnt] = u;
        }
        if (!id[v]) {
            cnt++;
            id[v] = cnt;
            name[cnt] = v;
        }
        graph[id[u]].push_back(id[v]);
    }
    for (int i = 1; i <= n; i++) {
        if(num[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            if (j != ans[i].size() - 1) {
                cout << name[ans[i][j]] << ", ";
            } else {
                cout << name[ans[i][j]] << '\n';
            }
        }
        ans[i].clear();
    }
    for(int i = 1; i <= n; i ++) {
        graph[i].clear();
    }
    cout << '\n';
}

int main() {
    int tc = 0;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        tc++;
        cout << "Calling circles for data set " << tc << '\n';
        solve();
    }
    return 0;
}
