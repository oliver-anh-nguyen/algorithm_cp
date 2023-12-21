#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int l = n / 2;
      int r = n;
    while (l < r) {
        int m = l + (r-l)/2;
      bool valid = true;
      if (m < n - m) {
        valid = false;
      }
      for (int i = 0; i < n - m; i++) {
        if (a[i] < 2*a[i + m]) {
          valid = false;
          break;
        }
      }
      if (valid) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << r << '\n';
    return 0;
}
