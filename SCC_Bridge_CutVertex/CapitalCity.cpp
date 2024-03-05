#include <iostream>
#include <stack>

using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define MAXN 400005

vii DSK[MAXN];
int out_degree[MAXN];
int num[MAXN], low[MAXN], pos[MAXN];
stack <int> S;
int counter = 0;
int num_cmp = 0;
int reg[MAXN];
vector <int> new_graph[MAXN];

void tarjan(int u){
    num[u] = low[u] = ++counter;
    S.push(u);
    for(ii v : DSK[u]){
        if(pos[v.se])
            continue;
        pos[v.se] = 1;
        if(num[v.fi])
            low[u] = min(low[u], num[v.fi]);
        else{
            tarjan(v.fi);
            low[u] = min(low[v.fi], low[u]);
        }
    }
    if(num[u] == low[u]){
        int v;
        num_cmp++;
        do{
            v = S.top();
            S.pop();
            new_graph[num_cmp].push_back(v);
            reg[v] = num_cmp;
            num[v] = low[v] = INT_MAX;
        }while(u != v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int num_edges = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        num_edges += 1;
        DSK[u].push_back({v, i});
    }
    for(int i = 1; i <= n; i++){
        if(!num[i])
            tarjan(i);
    }
    for(int i = 1; i <= n; i++){
        for(ii v : DSK[i]){
            if(reg[v.fi] != reg[i]){
                out_degree[reg[i]]++;
            }
        }
    }
    int count_zero_degree = 0;
    vector <int> res;
    for(int i = 1; i <= num_cmp; i++)
        if(out_degree[i] == 0){
            for(int v: new_graph[i])
                res.push_back(v);
            count_zero_degree++;
        }
    if(count_zero_degree > 1)
        return cout << 0, 0;
    sort(res.begin(), res.end());
    cout << (int)res.size() << '\n';
    for(int v: res)
        cout << v << ' ';
}
