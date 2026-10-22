class MinStack {
private:
    stack<long long>st;
    stack<long long>stMin;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(stMin.empty()) stMin.push(val);
        else stMin.push(min(stMin.top(),(long long)val));
    }
    
    void pop() {
        st.pop();
        stMin.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stMin.top();
    }
};
