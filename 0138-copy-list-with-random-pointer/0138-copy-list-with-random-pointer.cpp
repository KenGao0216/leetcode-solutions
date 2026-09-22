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
        if(!head) return nullptr;
        for(Node *cur = head; cur; cur = cur->next->next){
            Node *cur_next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = cur_next;
        }
        for(Node *cur = head; cur; cur = cur->next->next){
            if(cur->random) cur->next->random = cur->random->next;
        }

        Node dum = Node(-1);
        Node *copy = &dum;
        for(Node *cur = head; cur; cur = cur->next){
                Node *cur_copy = cur->next;
                cur->next = cur->next->next;
                copy->next = cur_copy;
                copy = copy->next;
        }
        
        return dum.next;
    }
};