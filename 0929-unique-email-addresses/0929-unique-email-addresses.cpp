class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>s;
        for(string &e: emails){
            int at_id = e.find('@');
            string end = e.substr(at_id);
            erase(e, '.');
            int plus_id = e.find('+');
            int at_id2 = e.find('@');
            string start = (plus_id == -1 ? e.substr(0, at_id2) : e.substr(0, plus_id));
            e = start + end;
            //cout<<e<<" ";
            s.insert(e);
        }
        return s.size();
    }
};