class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            // Encode the new minimum
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.top() < mini) {
            // Top is encoded, restore previous minimum
            mini = 2LL * mini - st.top();
        }

        st.pop();
    }

    int top() {
        if (st.top() < mini) {
            // Encoded value represents current minimum
            return mini;
        }

        return st.top();
    }

    int getMin() {
        return mini;
    }
};