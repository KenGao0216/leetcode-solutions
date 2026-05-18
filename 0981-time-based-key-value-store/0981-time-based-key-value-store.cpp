class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto id = upper_bound(m[key].begin(), m[key].end(), make_pair(timestamp, "~"));
        if(id == m[key].begin()) return "";
        --id;
        return id->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */