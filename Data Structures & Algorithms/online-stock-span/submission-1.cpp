class StockSpanner {
public:
    stack<int>st;
    stack<int>temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int cnt=1;
        while(!st.empty() && st.top()<=price){
                cnt++;
                temp.push(st.top());
                st.pop();
        }

        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        st.push(price);
        return cnt;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */