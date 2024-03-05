#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

#define MAX 10005
vector<int>adj[MAX];
bool visited[MAX]={false}, visited2[MAX]={false};
stack<int> st;

void dfs(int v) {
    visited[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];
        if(!visited[u]) {
            dfs(u);
        }
    }
    st.push(v);
}

void dfs2(int v) {
    visited2[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];
        if(!visited2[u]) {
            visited2[u] = true;
            dfs2(u);
        }
    }
}

int main() {
    int T;
    int n, m, u, v, cnt;
    cin >> T;
    while (T--){
        cnt = 0;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            visited[i] = false;
            visited2[i] = false;
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for(int i = 1; i <= n; i++) {
            if (!visited[i])
               dfs(i);
        }

        while (!st.empty()) {
            int x = st.top();
            if (!visited2[x]){
                cnt++;
                dfs2(x);
            }
            st.pop();
        }
        cout << cnt << endl;
    }
}
