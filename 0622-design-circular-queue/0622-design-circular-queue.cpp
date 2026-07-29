class MyCircularQueue {

    struct Node{
        int val;
        Node *next;
        Node(int v): val(v), next(nullptr){}
    };

public:
    Node *front;
    Node *back;
    int size;
    int cap;
    MyCircularQueue(int k) {
        front = nullptr;
        back = nullptr;
        size = 0;
        cap = k;
    }
    //1 -> 2 -> 3 
    bool enQueue(int value) {
        if(size==cap) return false;
        if(size==0) {
            front = new Node(value);
            back = front;
        }else{
            Node *newNode = new Node(value);
            back->next = newNode;
            back = newNode;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;
        if(size==1) {delete front;}
        else{
        Node *tmp = front;
        front = front->next;
        delete tmp;
        }
        size--;
        return true;
    }
    
    int Front() {
        return size && front? front->val: -1;
    }
    
    int Rear() {
        return size && back? back->val:-1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size>=cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */