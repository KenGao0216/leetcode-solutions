/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int>m;
        ListNode *ans =nullptr;
        ListNode *cur = headA;
        while(cur) {m[cur]++; cur = cur->next;}
        cur = headB;
        while(cur) {m[cur]++; cur = cur->next;}
        for(auto [x,y]: m) cout<<x->val<<" "<<y<<"\n";
        for(auto [x,y]:m) if(y==2) {ans = x; break;} 
        
        return ans ;
    }
};