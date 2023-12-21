//
//  main.cpp
//  DimaXOR
//
//  Created by AnhNguyen on 12/12/2023.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(int n, int m, vector<vector<int>>& matrix) {
    // Check if there is at least one column with XOR > 0
    for (int j = 0; j < m; ++j) {
        int column_xor = 0;
        for (int i = 0; i < n; ++i) {
            column_xor ^= matrix[i][j];
        }
        if (column_xor > 0) {
            // If there is a column with XOR > 0, we can select it
            return vector<int>(n, j + 1);
        }
    }

    // If all columns have XOR == 0, it's not possible to get a non-zero XOR
    return {};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Input matrix values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Solve the problem
    vector<int> result = solve(n, m, matrix);

    // Output the result
    if (result.empty()) {
        cout << "NIE" << endl;
    } else {
        cout << "TAK" << endl;
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
