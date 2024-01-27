

#include <iostream>

using namespace std;

char parent[256];

char findSet(char u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void join(char u, char v) {
    char pu = findSet(u);
    char pv = findSet(v);
    if (pu == pv) {
        return;
    }
    if (pu > pv) {
        swap(pu, pv);
    }
    parent[pv] = pu;
}

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    
    for (char c = 'a'; c <= 'z'; c++) {
        parent[c] = c;
    }
    
    for (int i = 0; i < A.size(); i++) {
        join(A[i], B[i]);
    }
    
    for (int i = 0; i < C.size(); i++) {
        cout << findSet(C[i]);
    }
    
    cout << '\n';
    return 0;
}
