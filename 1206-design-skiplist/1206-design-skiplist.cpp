class Skiplist {
    static const int ML = 16;
    struct Node{
        int val;
        vector<Node*>next;
        Node(int v, int l): val(v), next(l, nullptr){}
    };
public:
    Node *head;

    Skiplist() {
        head = new Node(-1, ML);
    }
    
    bool search(int target) {
        Node *cur = head;
        for(int l = ML-1; l>=0; l--){
            while(cur->next[l] && cur->next[l]->val < target) cur = cur->next[l];
        }
        //cur is on bottom level and is less than target, move 1 step forward
        cur = cur->next[0];
        return cur && cur->val == target;
    }
    
    void add(int num) {
       vector<Node*>pred(ML);
       Node *cur = head;
       for(int l = ML-1; l>=0; l--){
            while(cur->next[l] && cur->next[l]->val < num) cur = cur->next[l]; // ----> 
            pred[l] = cur;
            // |
            // |
            // v
       }
       int lvl = 1;
       while(lvl <ML && rand()%2) lvl++;
       Node *newNode = new Node(num, lvl);
       for(int l = 0; l<lvl; ++l){
            Node *prev = pred[l];
            Node *prev_next = prev->next[l];
            prev->next[l] = newNode;
            newNode->next[l] = prev_next;
       }
    }

    bool erase(int num) {
       vector<Node*>pred(ML);
       Node *cur = head;
       for(int l = ML-1; l>=0; l--){
            while(cur->next[l] && cur->next[l]->val < num) cur = cur->next[l]; // ----> 
            pred[l] = cur;
            // |
            // |
            // v
       }
       Node *target = pred[0]->next[0];
       if(!target || target->val != num) return false;
       for(int l = 0; l<target->next.size(); ++l){
            if(pred[l]->next[l] != target) break;
            pred[l]->next[l] = target->next[l];
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