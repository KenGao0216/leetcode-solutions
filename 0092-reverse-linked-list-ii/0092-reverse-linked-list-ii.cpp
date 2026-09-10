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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode *dummy = new ListNode(0, head);
        ListNode *Left_pre = dummy;
        ListNode *Left = head; ListNode *Right = head;
        while(cnt < left) {
            Left_pre = Left_pre->next;
            Left = Left->next; 
            Right = Right->next; 
            cnt++;
        }
        while(cnt < right) {Right = Right->next; cnt++;}
        ListNode *Right_next = Right->next;

        ListNode *nxt, *pre = Left_pre;
        for(ListNode *cur = Left; cur!=Right_next;){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt; 
        }
        Left_pre ->next = Right;
        Left->next = Right_next;

        return dummy->next;
    }
};