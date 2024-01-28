#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int result = 0;

    // Tính tổng cộng dồn theo từng hàng
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    // Duyệt qua tất cả các cặp cột
    for (int left = 0; left < cols; ++left) {
        for (int right = left; right < cols; ++right) {
            unordered_map<int, int> prefixSumCount;
            int currentSum = 0;

            // Duyệt qua từng hàng để tính tổng của các phần tử trong khoảng từ left đến right
            for (int i = 0; i < rows; ++i) {
                int colSum = matrix[i][right] - (left > 0 ? matrix[i][left - 1] : 0);
                currentSum += colSum;
                
                // Nếu tổng hiện tại bằng giá trị mục tiêu, tăng kết quả
                if (currentSum == target) {
                    result++;
                }

                // Nếu có một giá trị trước đó có tổng (currentSum - target), thì cộng thêm vào kết quả
                if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) {
                    result += prefixSumCount[currentSum - target];
                }

                // Cập nhật bảng đếm các tổng prefix
                prefixSumCount[currentSum]++;
            }
        }
    }

    return result;
}

int main() {
    // Test các ví dụ
    vector<vector<int>> matrix1 = {{0,1,0},{1,1,1},{0,1,0}};
    int target1 = 0;
    cout << numSubmatrixSumTarget(matrix1, target1) << endl; // Output: 4

    vector<vector<int>> matrix2 = {{1,-1},{-1,1}};
    int target2 = 0;
    cout << numSubmatrixSumTarget(matrix2, target2) << endl; // Output: 5

    vector<vector<int>> matrix3 = {{904}};
    int target3 = 0;
    cout << numSubmatrixSumTarget(matrix3, target3) << endl; // Output: 0

    return 0;
}

