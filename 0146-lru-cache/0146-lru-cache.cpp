class LRUCache {
public:
    struct Node{
        int key, val; 
        Node *next, *prev;
        Node(int k, int v): key{k}, val{v}{}
    };
    Node *head, *tail;
    unordered_map<int, Node*>m; //key -> Node 
    int cap, sz;
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        sz= 0;
    }

    
    int get(int key) {
        if(!m[key]) return -1;
        Node *cur = m[key];
        unlink(cur);
        mtf(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(m[key]){
            Node *cur = m[key];
            cur->val = value;
            unlink(cur);
            mtf(cur);
        }
        else{
            sz++;
            if(sz>cap){
                //evict
                Node *lru =tail->prev;
                unlink(lru);
                m.erase(lru->key);
                delete lru;
                sz--;
            }
            Node *cur = new Node(key, value);
            m[key] = cur;
            mtf(cur);
        }
    }
    
    void unlink(Node *cur){
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    void mtf(Node *cur){
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */