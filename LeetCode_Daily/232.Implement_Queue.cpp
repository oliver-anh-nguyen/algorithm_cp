#include <iostream>
#include <queue>

class MyQueue {
private:
    std::queue<int> q;

public:
    MyQueue() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }

    int peek() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyQueue obj;
    obj.push(1);
    int ret_2 = obj.pop();
    int ret_3 = obj.peek();
    bool ret_4 = obj.empty();

    // Your MyQueue object will be instantiated and called as such:
    std::cout << "ret_2: " << ret_2 << std::endl;
    std::cout << "ret_3: " << ret_3 << std::endl;
    std::cout << "ret_4: " << ret_4 << std::endl;

    return 0;
}
