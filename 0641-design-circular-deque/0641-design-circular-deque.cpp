class MyCircularDeque {
public:
    vector<int>dq;
    int size;
    int maxSize;
    int front;
    MyCircularDeque(int k) {
        size = 0;
        maxSize = k;
        front = 0;
        dq = vector<int>(k);
    }
    
    bool insertFront(int value) {
        if(size == maxSize) return false;
        front = (front-1 + maxSize) %maxSize;
        dq[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size == maxSize) return false;
        dq[(front+size+maxSize)%maxSize] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;
        front = (front+1+maxSize)%maxSize;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0)return -1;
        return dq[front];
    }
    
    int getRear() {
        if(size==0)return -1;
        return dq[(front+size-1)%maxSize];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */