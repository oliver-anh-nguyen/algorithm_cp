#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n, m, d, s;
    cin >> n >> m >> d >> s;
    vector<vector<ii>> p(n);
    for (int i = 0; i < d; i++) {
        int pi, mi, ti;
        cin >> pi >> mi >> ti;
        pi--;
        p[pi].push_back({mi, ti});
    }
    vector<int> sick(n, -1);
    for (int i = 0; i < s; i++) {
        int pi, ti;
        cin >> pi >> ti;
        pi--;
        sick[pi] = ti;
    }
    int res = 0;
    for (int mi = 0; mi <= m; mi++) {
        bool valid = 1;
        for (int i = 0; i < n; i++) {
            int dt = 1e9;
            for (auto p : p[i]) {
                if (p.first == mi) {
                    dt = min(dt, p.second);
                }
            }
            if (sick[i] <= dt && sick[i] != -1) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (auto p : p[i]) {
                    if (p.first == mi) {
                        cnt++;
                        break;
                    }
                }
            }
            res = max(res, cnt);
        }
    }
    cout << res;
    return 0;
}
