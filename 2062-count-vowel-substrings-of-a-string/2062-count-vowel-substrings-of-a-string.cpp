class Solution {
public:
    int countVowelSubstrings(string word) {
        return f(word, 5) - f(word, 4);
    }
     bool vowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int idx(char c){
        if(c=='a') return 0;
        if(c=='e') return 1;
        if(c=='i') return 2;
        if(c=='o') return 3;
        return 4;
    }
    int f(string s, int k){
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        vector<int>freq(5, 0);
        int distinct = 0;
        while(r<n){
            if(!vowel(s[r])){
                fill(freq.begin(), freq.end(), 0);
                distinct = 0;
                l = r+1;
                r++;
                continue;
            }
            int id = idx(s[r]);
            freq[id]++;
            if(freq[id] == 1) distinct++;
            while(distinct > k){
                int leftId = idx(s[l]);
                freq[leftId]--;
                if(freq[leftId] == 0) distinct--;
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        return ans;
    }

};