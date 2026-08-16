class AllOne {
    struct Node{
        string key;
        int val;
        Node *next;
        Node *prev;
        Node(string k): key{k}, val{1}, next{nullptr}, prev{nullptr}{}
    };
   public:
    unordered_map<string, Node*>m;
    Node *front;
    Node *back;
    AllOne() {
        front = new Node("1front");
        back = new Node("1back");
        front->next = back;
        back->prev = front;
    }
    
    void inc(string key) {
        if(!m[key]){
            Node *newNode = new Node(key);
            newNode->prev = back->prev;
            back->prev->next = newNode;

            newNode->next = back;
            back->prev = newNode;

            m[key] = newNode;
        }
        else{
            Node *cur = m[key];
            cur->val++;
            while(cur->prev != front){
                if(cur->val > cur->prev->val){
                    Node *cur_prev = cur->prev;
                    Node *cur_next = cur->next;

                    cur->prev = cur_prev->prev;
                    cur_prev->prev->next = cur;

                    cur_prev->next = cur_next;
                    cur_next->prev = cur_prev;

                    cur_prev->prev = cur;
                    cur->next = cur_prev;
                }
                else break;
            }
        }
    }
    
    void dec(string key) {
        Node *cur = m[key];
        if(cur->val == 1){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            m.erase(key);
        }
        else{
            cur->val--;
            while(cur->next != back){
                if(cur->val < cur->next->val){
                    Node *cur_next = cur->next;
                    Node *cur_prev = cur->prev;

                    cur->next = cur_next->next;
                    cur_next->next->prev = cur;

                    cur_prev->next = cur_next;
                    cur_next->prev = cur_prev;

                    cur_next->next = cur;
                    cur->prev = cur_next;
                }
                else break;
            }
        }
    }
    
    string getMaxKey() {
        return front->next != back ? front->next->key : "";
    }
    
    string getMinKey() {
        return back->prev != front ? back->prev->key : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */