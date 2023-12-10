class MyQueue {
public:
    stack<int> st,helper;
    MyQueue() {
        
    }
    void push(int x) {
        if(st.size() == 0)
        {
            st.push(x);
            return;
        }
        while(st.size())
        {
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(helper.size())
        {
            st.push(helper.top());
            helper.pop();
        }
    }
    
    int pop() {
        int temp = st.top();
        st.pop();
        return temp;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.size()==0) return true;
        return false;
    }
};
