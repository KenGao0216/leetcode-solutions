/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node * lvl = root;
        while(lvl){
            Node* cur = lvl;
            while(cur){
                if(cur->left){
                    if(cur->right) cur->left->next = cur->right;
                    else{
                        Node *tmp = cur;
                        while(tmp->next){
                            if(tmp->next->left) {cur->left->next = tmp->next->left; break;}
                            else if(tmp->next->right) {cur->left->next = tmp->next->right; break;}
                            tmp = tmp->next;
                        }
                    }
                }
                if(cur->right){
                    Node *tmp = cur;
                        while(tmp->next){
                            if(tmp->next->left) {cur->right->next = tmp->next->left; break;}
                            else if(tmp->next->right) {cur->right->next = tmp->next->right; break;}
                            tmp = tmp->next;
                        }
                }
                cur = cur->next;
            }
            Node *tmp = lvl; Node *next = nullptr;
            while(tmp){
                if(tmp-> left) {next = tmp->left; break;}
                else if(tmp-> right) {next = tmp->right; break;}
                tmp = tmp->next;
            }
            lvl = next;
        }
        return root;
    }
};