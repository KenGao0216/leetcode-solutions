class FileSystem {
    class Node{
        public:
            string name;
            bool isFile = false;
            string content;
            map<string, Node*> children;

            Node(string Name){
                name = Name;
                isFile = false;
                content = "";
            }
    };
public:
    Node *root;
    FileSystem() {
        root = new Node("");
    }
    
    vector<string> ls(string path) {
        vector<string>parts = split(path);
        Node *cur = root;
        for(string &p:parts){
            cur = cur->children[p];
        }
        if(cur->isFile) return {cur->name};
        
        vector<string>ans;
        for(auto &[x,y]:cur->children) ans.push_back(x);
        return ans;
    }
    
    void mkdir(string path) {
        vector<string>parts = split(path);
        Node*cur = root;
        for(string &p:parts){
            if(!cur->children.count(p)) cur->children[p] = new Node(p);
            cur = cur->children[p];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string>parts = split(filePath);
        Node*cur = root;
        for(string &p:parts){
            if(!cur->children.count(p)) cur->children[p] = new Node(p);
            cur = cur->children[p];
        }
        cur->isFile = true;
        cur->content+=content;
    }
    
    string readContentFromFile(string filePath) {
        string path = filePath;
        Node * cur = root;
        vector<string>parts = split(path);
        for(string &p:parts)
            cur = cur->children[p];
        
        return cur->content;
    }

    vector<string> split(string path){
        vector<string>parts;
        string cur;
        for(char c: path){
            if(c == '/'){
                if(!cur.empty()){
                    parts.push_back(cur);
                    cur = "";
                }
            }
            else cur+=c;
        }
        if(!cur.empty()) parts.push_back(cur);

        return parts;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */