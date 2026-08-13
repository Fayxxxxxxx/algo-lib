//搞两个线性结构 一个存放数据 一个存放当前情况下里面的最小数字 

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> values;
    stack<int> Min;
    MinStack() {
        
    }
    
    void push(int x) {
        if(values.empty()||Min.top()>x)
        {
            Min.push(x);
            values.push(x);
        }
        else
        {
            Min.push(Min.top());
            values.push(x);
        }
    }
    
    void pop() {
        values.pop();
        Min.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return Min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */