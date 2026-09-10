class Solution {
public:
    int kthGrammar(int n, int k) {
        stack<int>st;
        while(k>1){
            st.push(k);
            k = ceil((double)(k)/2.0);
        }
        int cur = 0;
        while(!st.empty()) {
            int top = st.top();
            if(top % 2 == 0 && cur == 0) cur = 1;
            else if(top%2==1 && cur == 0) cur = 0;
            else if(top%2==0 && cur == 1) cur =0;
            else if(top%2==1 && cur == 1) cur = 1;
            st.pop();
        }
        return cur;
    }
};

