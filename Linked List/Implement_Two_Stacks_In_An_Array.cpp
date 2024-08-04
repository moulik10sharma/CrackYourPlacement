class twoStacks {
public:
    stack<int> stack1;
    stack<int> stack2;
    twoStacks() {}
    void push1(int x) {
        stack1.push(x);
    }
    void push2(int x) {
        stack2.push(x);
    }
    int pop1() {
        if (!stack1.empty()) {
            int top = stack1.top();
            stack1.pop();
            return top;
        }
        return -1;
    }
    int pop2() {
        if (!stack2.empty()) {
            int top = stack2.top();
            stack2.pop();
            return top;
        }
        return -1;
    }
};