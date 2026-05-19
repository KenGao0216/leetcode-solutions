class BrowserHistory {
    class Node{
        public: 
            string val;
            Node *prev;
            Node *next;
            Node(string v): val(v), prev(nullptr), next(nullptr){}
    };
public:
    Node *chain;
    BrowserHistory(string homepage) {
        chain = new Node(homepage);
    }
    
    void visit(string url) {
        Node *cur = new Node(url);
        cur->next = chain; 
        chain->prev = cur;
        chain = cur;
    }
    
    string back(int steps) {
        int k = 0;
        while(chain->next && k<steps) {chain = chain->next; ++k;}
        return chain->val;
    }
    
    string forward(int steps) {
        int k = 0;
        while(chain->prev && k<steps) {chain = chain->prev; ++k;}
        return chain->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

