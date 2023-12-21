//
//  main.cpp
//  Cola
//
//  Created by AnhNguyen on 21/11/2023.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    // n = 0.5a + b + 2c <=> 2n = a + 2b + 4c
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if ((2*n - i - 2*j) % 4 == 0) {
                int z = (2*n - i - 2*j) / 4;
                if (z >= 0 && z <= c) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}



