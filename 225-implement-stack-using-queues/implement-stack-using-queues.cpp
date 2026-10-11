class MyStack {
public:
    queue<int> q;
    int n;
    MyStack() { n = 0; }

    void push(int x) {
        q.push(x);
        n++;
        for (int i = 0; i < n-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        n--;
        return val;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */