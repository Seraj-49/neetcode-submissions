class MinStack {
public:
   stack<int> st;
   stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minSt.push(val);
        } else {
            st.push(val);
            minSt.push(min(val,minSt.top()));
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return minSt.top(); 
    }
};
