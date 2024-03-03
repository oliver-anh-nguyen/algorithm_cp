#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, s, p;
        cin >> n >> s >> p;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int score;
            cin >> score;
            if (score == 0 && p != 0) {
                continue;
            }
            if (score >= 3 * (p - 1) + 1) {
                res++;
            } else if (s > 0 && score >= 3 * (p - 1) - 1) {
                s--;
                res++;
            }
        }
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}
