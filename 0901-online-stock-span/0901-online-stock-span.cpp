class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cur = 1;
        while(!st.empty() && st.top().first <= price){
            cur+=st.top().second;
            st.pop();
        }
        st.push({price, cur});
        return cur;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */