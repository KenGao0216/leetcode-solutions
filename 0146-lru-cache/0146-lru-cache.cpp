class LRUCache {
    struct Node{
        int key;
        Node *next;
        Node *prev;

        Node(int k): key{k}, next{nullptr}, prev{nullptr}{}
    };
    // front-> first -> ... -> ... last <- LRU (dummy)
    Node *front;
    Node *LRU;
    unordered_map<int,int>m;
    unordered_map<int, Node*>m1;
    int size;
    int cap;
public:
    LRUCache(int capacity) {
        front = new Node (-2);
        LRU = new Node(-1);
        front->next = LRU;
        LRU->prev = front;
        size = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        Node *cur = m1[key];
        Node* cur_next = cur->next;
        Node *cur_prev = cur->prev;
        cur_next->prev = cur_prev;
        cur_prev->next = cur_next;
        Node *front_next = front->next;
        front->next = cur;
        cur->prev = front;
        cur->next = front_next;
        front_next->prev = cur;
        m1[key] = cur;
        return m[key];
    }
    
    void put(int key, int value) {
        if(!m.count(key)){
            Node *newNode = new Node(key);
            newNode->next = front->next;
            newNode->prev = front;
            front->next->prev = newNode;
            front->next = newNode;
            size++;
            m[key] = value;
            m1[key] = newNode;
            if(size==1) LRU->prev = front->next;
            if(size>cap) {
                    Node *tmp = LRU->prev;
                    Node *tmp1 = tmp->prev;
                    LRU->prev = tmp1;
                    tmp1->next = LRU;
                    m.erase(tmp->key);
                    m1.erase(tmp->key);
                    delete tmp;
                    size--;
                }
        }   
        else{
            Node *cur = m1[key];
            Node* cur_next = cur->next;
            Node *cur_prev = cur->prev;
            cur_next->prev = cur_prev;
            cur_prev->next = cur_next;
            Node *front_next = front->next;
            front->next = cur;
            cur->prev = front;
            cur->next = front_next;
            front_next->prev = cur;

            m1[key] = cur;
            m[key] = value;
        }        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */