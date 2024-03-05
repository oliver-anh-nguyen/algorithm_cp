#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;

#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define PROB "Checkposts"
#define MAXN 400005

int cost[MAXN];

vii DSK[MAXN];

int num[MAXN], low[MAXN], pos[MAXN];
stack <int> S;
int cnt = 0;
int num_cmp = 0;
int reg[MAXN];
int reg_cost[MAXN], num_min_cost[MAXN];

void Tarjan(int u){
    num[u] = low[u] = ++cnt;
    S.push(u);
    for(ii v : DSK[u]){
        if(pos[v.se])
            continue;
        pos[v.se] = 1;
        if(num[v.fi])
            low[u] = min(low[u], num[v.fi]);
        else{
            Tarjan(v.fi);
            low[u] = min(low[v.fi], low[u]);
        }
    }
    if(num[u] == low[u]){
        int v;
        num_cmp++;
        reg_cost[num_cmp] = INT_MAX;
        do{
            v = S.top();
            S.pop();
            reg[v] = num_cmp;
            if(reg_cost[num_cmp] > cost[v]){
                reg_cost[num_cmp] = cost[v];
                num_min_cost[num_cmp] = 0;
            }
            if(cost[v] == reg_cost[num_cmp])
                num_min_cost[num_cmp]++;
            num[v] = low[v] = INT_MAX;
        }while(u != v);
    }
}

int main(){
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    cin >> m;
    int num_edges = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        num_edges += 1;
        DSK[u].pb({v, i});
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            Tarjan(i);

    ll res = 0, num_way = 1;
    for(int i = 1; i <= num_cmp; i++){
        res += reg_cost[i];
        num_way = (num_way * num_min_cost[i])%MOD;
    }
    cout << res << ' ' << num_way << '\n';
}
