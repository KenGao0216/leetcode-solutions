class AllOne {
    struct Node{
        int val;
        Node *next;
        Node *prev;
        unordered_set<string>keys;
        Node(int x): val{x}, next{nullptr}, prev{nullptr}{}
    };
   public:
    unordered_map<int, Node*>m;
    unordered_map<string,int>freq;
    Node *front;
    Node *back;
    AllOne() {
        front = new Node(1e5);
        back = new Node(0);
        front->next = back;
        back->prev = front;
    }
    
    void inc(string key) {
        if(!freq[key]){
            freq[key] = 1;
            if(!m[1]){
                Node *newNode = new Node(1);
                newNode->next = back;
                newNode->prev = back->prev;
                back->prev->next = newNode;
                back->prev = newNode;

                newNode->keys.insert(key);
                m[1] = newNode;
            }
            else m[1]->keys.insert(key);
        }
        else{
            int oldFreq = freq[key];
            int newFreq = oldFreq + 1;

            Node* cur = m[oldFreq];
            Node* prev = cur->prev; 

            cur->keys.erase(key);
            if (prev != front && prev->val == newFreq) prev->keys.insert(key);
            
            else {
                Node* newNode = new Node(newFreq);
                newNode->keys.insert(key);

                newNode->prev = prev;
                newNode->next = cur;

                prev->next = newNode;
                cur->prev = newNode;

                m[newFreq] = newNode;
            }

            freq[key] = newFreq;

            if (cur->keys.empty()) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;

                m.erase(oldFreq);
                delete cur;
            }
        }
    }
    
    void dec(string key) {
    int oldFreq = freq[key];
    int newFreq = oldFreq - 1;

    Node* cur = m[oldFreq];
    Node* next = cur->next;

    cur->keys.erase(key);

    if (newFreq == 0) {
        freq.erase(key);
    }
    else {
        if (next != back && next->val == newFreq) {
            next->keys.insert(key);
        }
        else {
            Node* newNode = new Node(newFreq);
            newNode->keys.insert(key);

            newNode->prev = cur;
            newNode->next = next;

            cur->next = newNode;
            next->prev = newNode;

            m[newFreq] = newNode;
        }

        freq[key] = newFreq;
    }

    if (cur->keys.empty()) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        m.erase(oldFreq);
        delete cur;
    }
}
    
    string getMaxKey() {
        return front->next != back ? *front->next->keys.begin() : "";
    }
    
    string getMinKey() {
        return back->prev != front ? *back->prev->keys.begin() : "";
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