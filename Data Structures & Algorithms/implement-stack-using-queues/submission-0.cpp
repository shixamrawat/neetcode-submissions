class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty())return -1;
        while(q1.size()!=1){
            int top=q1.front();
            q1.pop();
            q2.push(top);
        }
        int remove=q1.front();
        q1.pop();
        while(!q2.empty()){
            int top=q2.front();
            q2.pop();
            q1.push(top);
        }
        return remove;
    }
    
    int top() {
        if(q1.empty())return -1;
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */