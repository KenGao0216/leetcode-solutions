class LRUCache {
    class Node{
        public: 
            int key;
            int value;
            Node* prev;
            Node *next;
            Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr){}
    };
public:
    int cap;
    unordered_map<int, Node*>mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node (-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node *node = mp[key];
        MTF(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node *node = mp[key];
            node->value = value;
            MTF(node);
        }
        else{
            if(mp.size() == cap){
                Node * lru = removeLRU();
                mp.erase(lru->key);
                delete lru;
            }
            Node *node = new Node(key, value);
            mp[key] = node;
            ATF(node);
        }
    }

    void remove(Node* node){
        node->prev->next =node->next;
        node->next->prev = node->prev;
    }
    void ATF(Node *node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void MTF(Node *node){
        remove(node);
        ATF(node);
    }
    Node* removeLRU() {
        Node* lru = tail->prev;
        remove(lru);
        return lru;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */