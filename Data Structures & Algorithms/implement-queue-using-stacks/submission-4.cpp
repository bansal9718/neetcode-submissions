class MyQueue {
public:
stack<int>st1;
stack<int>st2;
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
        return;
    }
    
    int pop() {
        
        if(st1.empty()) return -1;
        else
        while(st1.size()>1) {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        st1.pop();

        while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
        }
        return ans;
    }
    
    int peek() {
        
        if(st1.empty()) return -1;

        while(st1.size()>1) {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        
        if(st1.size()==0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */