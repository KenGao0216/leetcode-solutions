class Skiplist {
    
    struct Node{
        int val;
        vector<Node*>next;
        Node(int v, int l){
            val = v;
            next.resize(l, nullptr);
        }
    };
public:
    const int ML = 16;
    Node *head; 
    
    Skiplist() {
        head= new Node(-1, ML);
    }
    
    bool search(int target) {
        Node *cur = head;
        for(int lvl = ML-1; lvl>=0; lvl--){
            while(cur->next[lvl] && cur->next[lvl]->val < target) cur = cur->next[lvl];
        }
        cur = cur->next[0];
        return cur && cur->val == target;
    }
    
    void add(int num) {
        vector<Node*>pred(ML);
        Node *cur = head;
        for(int lvl = ML-1; lvl>=0; lvl--){
            while(cur->next[lvl] && cur->next[lvl]->val < num) cur = cur->next[lvl];
            pred[lvl]=cur;
        }
        int l= 1;
        while(l<ML && rand() %2) ++l;
        Node *newNode = new Node(num, l);
        for(int i = 0; i<l; ++i){
            Node *nxt = pred[i]->next[i];
            pred[i]->next[i] = newNode;
            newNode->next[i] = nxt;
        }
    }
    
    bool erase(int num) {
        vector<Node*>pred(ML);
        Node *cur = head;
        for(int lvl = ML-1; lvl>=0; lvl--){
            while(cur->next[lvl] && cur->next[lvl]->val < num) cur = cur->next[lvl];
            pred[lvl] =cur;
        }
        Node *target = pred[0]->next[0];
        if(!target || target->val != num) return false;

        for(int i = 0; i<target->next.size(); ++i){
            if(pred[i]->next[i]->val!=num) break;
            pred[i]->next[i] = target->next[i];
        }
        delete target;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */