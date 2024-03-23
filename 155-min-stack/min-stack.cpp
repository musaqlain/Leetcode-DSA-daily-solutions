class MinStack {
private:
    stack<int> regular;
    stack<int> minimum;
public:
    MinStack() {
        minimum.push(INT_MAX);
    }
    
    void push(int val) {
        regular.push(val);
        minimum.push(min(val, minimum.top()));
    }
    
    void pop() {
        regular.pop();
        minimum.pop();
    }
    
    int top() {
        return regular.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */