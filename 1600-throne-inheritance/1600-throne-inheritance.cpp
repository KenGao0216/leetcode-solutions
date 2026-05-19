class ThroneInheritance {
    class Node{
        public: 
            string name;
            bool dead;
            vector<Node*>children;
            Node(string n): name(n),dead(false){}
    };
public:
    Node *root;
    unordered_map<string, Node*>m;
    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        m[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node *newNode = new Node(childName);
        m[childName] = newNode;
        m[parentName]->children.push_back(newNode);
    }
    
    void death(string name) {
        m[name]->dead = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(Node* root, vector<string>&ans){
        if(!root->dead) ans.push_back(root->name);
        for(int i = 0; i<root->children.size(); ++i){
            dfs(root->children[i], ans);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */