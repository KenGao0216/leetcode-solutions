/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>m;
        m[nullptr] = nullptr;
        for(Node *cur = head; cur; cur = cur->next) m[cur] = new Node(cur->val);
        for(Node *cur = head; cur; cur = cur->next) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
        }
        
        return m[head];
    }
};