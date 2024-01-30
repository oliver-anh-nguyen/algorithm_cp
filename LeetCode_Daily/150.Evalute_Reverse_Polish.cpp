#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        for (const auto& item : tokens) {
            if (std::isdigit(item[0])) {
                stack.push(std::stoi(item));
            } else {
                int second = stack.top();
                stack.pop();
                int first = stack.top();
                stack.pop();
                int total = 0;
                if (item == "/") {
                    total = first / second;
                } else if (item == "*") {
                    total = second * first;
                } else if (item == "+") {
                    total = second + first;
                } else if (item == "-") {
                    total = first - second;
                }
                stack.push(total);
            }
        }
        return stack.top();
    }
};

int main() {
    Solution solution;
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    int result = solution.evalRPN(tokens);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
