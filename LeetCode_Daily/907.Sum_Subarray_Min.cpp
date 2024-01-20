#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        stack<int> stack;
        long long res = 0;
        const int maxNum = 1e9 + 7;
        
        for (int i = 0; i <= arr.size(); ++i) {
            while (!stack.empty() && (i == arr.size() || arr[stack.top()] > arr[i])) {
                int curr = stack.top();
                stack.pop();
                int leftBoundary = stack.empty() ? -1 : stack.top();
                int rightBoundary = i;
                res = (res + static_cast<long long>(arr[curr]) * (curr - leftBoundary) * (rightBoundary - curr)) % maxNum;
            }
            stack.push(i);
        }
        
        return static_cast<int>(res);
    }
};
