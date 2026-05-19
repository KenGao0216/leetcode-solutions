class WordDictionary {
    class Node{
        public:
            bool isWord;
            vector<Node*> children;
            Node(){
                isWord = false;
                children = vector<Node*>(26, nullptr);
            }
    };
public:
    Node * root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *cur = root;
        for(char c: word){
            int idx = c-'a';
            if(!cur->children[idx]){
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string &word, int i, Node * node){
        if(!node) return false;
        if(i == word.length()) return node->isWord;
        if(word[i] == '.'){
            for(int j = 0; j<26; ++j){
                if(dfs(word, i+1, node->children[j])) return true;
            }
            return false;
        }
        int idx = word[i]- 'a';
        return dfs(word, i+1, node->children[idx]);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */