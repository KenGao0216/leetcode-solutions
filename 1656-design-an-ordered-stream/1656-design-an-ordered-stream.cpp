class OrderedStream {
    vector<string>s;
    int ptr;
public:
    OrderedStream(int n) {
        s = vector<string>(n+1, "");
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey] = value;
        vector<string>ans;
        while(ptr < s.size() && s[ptr] !="") {
            ans.push_back(s[ptr]);
            ptr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */