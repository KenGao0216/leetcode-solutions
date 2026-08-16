/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *cur = head;
        ListNode *ans = nullptr;
        ListNode *prevEnd = nullptr;
        bool once = false;
        while(true){
            ListNode *nextGroup = cur;
            for(int i = 0; i<k; ++i) { if(nextGroup) nextGroup = nextGroup->next; else return ans? ans:head ;}
            ListNode *prev = cur; 
            ListNode *start = prev;
            cur = cur->next;
            while(cur!=nextGroup){
                ListNode *nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt; 
            }
            if(!ans) ans = prev;
            if(prevEnd) prevEnd->next = prev; 
            start->next = nextGroup;
            prevEnd = start;
        }
    }
};