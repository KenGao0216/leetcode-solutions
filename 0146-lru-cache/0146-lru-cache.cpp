class LRUCache {
    struct Node{
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int k,int v): key(k),val(v), next(nullptr), prev(nullptr){}
    };
    Node *front;
    Node *back;
    int size;
    int cap;
    unordered_map<int, Node*>node;
public:
    LRUCache(int capacity) {
        front= new Node(-1,-1);
        back = new Node(-1,-1);
        front->next = back;
        back->prev = front;
        size= 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(!node.count(key)) return -1;
        Node *cur = node[key];
        Node *cur_prev = cur->prev;
        Node *cur_next = cur->next;
        cur_prev->next = cur_next;
        cur_next->prev = cur_prev;
        cur->next = front->next;
        cur->prev = front;
        front->next->prev = cur;
        front->next = cur;
        return cur->val;
    }
    
    void put(int key, int value) {

        if(node.count(key)){
            node[key]->val = value;
            int x = get(key);
            return;
        }
        
        Node *newNode = new Node(key,value);
        node[key] = newNode;
        newNode->next = front->next;
        
        front->next->prev = newNode;
        front->next = newNode;
        newNode->prev = front;
        size++;
        if(size>cap){
            Node *tmp = back->prev;
            Node *back_prev_prev = back->prev->prev;
            back_prev_prev->next = back;
            back->prev = back_prev_prev;
            node.erase(tmp->key);
            delete tmp;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */