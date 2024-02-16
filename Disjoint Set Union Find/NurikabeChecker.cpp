#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int maxN = 300*300 + 5;

int parent[maxN], ranks[maxN], setCount[maxN];
int row[maxN], col[maxN], number[maxN];

bool isWhite[305][305];
bool taken[maxN];

int findSet(int u) {
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
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

int main() {
    int p;
    cin >> p;
    for (int t = 1; t <= p; t++) {
        memset(parent, 0, sizeof((parent)));
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                if (ch == '.') {
                    isWhite[i][j] = true;
                } else {
                    isWhite[i][j] = false;
                }
            }
        }
        bool isCorrect = true;
        for (int i = 0; i < k; i++) {
            cin >> row[i] >> col[i] >> number[i];
            if (!isWhite[row[i] - 1][col[i] - 1]) {
                isCorrect = false;
            }
        }
        
        for (int i = 0; i < n * m; i++) {
            parent[i] = i;
            ranks[i] = 1;
        }
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (r + 1 < n && isWhite[r][c] == isWhite[r + 1][c]) {
                    unionSet(r * m + c, (r + 1) * m + c);
                }
                if (c + 1 < m && isWhite[r][c] == isWhite[r][c + 1]) {
                    unionSet(r * m + c, r * m + c + 1);
                }
            }
        }
        
        memset(taken, false, sizeof(taken));
        memset(setCount, 0, sizeof(setCount));
        
        for (int i = 0; i < n * m; i++) {
            parent[i] = findSet(i);
            setCount[parent[i]] += 1;
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (!isWhite[i][j] && !isWhite[i + 1][j] && !isWhite[i][j + 1] && !isWhite[i + 1][j + 1]) {
                    isCorrect = false;
                    break;
                }
            }
        }
        
        for (int i = 0; i < k; i++) {
            int index = (row[i] - 1) * m + (col[i] - 1);
            if (taken[parent[index]]) {
                isCorrect = false;
                break;
            } else {
                taken[parent[index]] = true;
            }
            
            if (setCount[parent[index]] != number[i]) {
                isCorrect = false;
                break;
            }
        }
        
        int blackRoot = -1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int index = r * m + c;
                if (isWhite[r][c]) {
                    if (!taken[parent[index]]) {
                        isCorrect = false;
                        break;
                    }
                } else {
                    if (blackRoot == -1) {
                        blackRoot = parent[index];
                    }
                    if (parent[index] != blackRoot) {
                        isCorrect = false;
                        break;
                    }
                }
            }
        }
        
        cout << "Puzzle #" << t << ": ";
        if (isCorrect) {
            cout << "Correct" << '\n';
        } else {
            cout << "Incorrect" << '\n';
        }
    }
    return 0;
}
