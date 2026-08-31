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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = vector{-1,-1};
        ListNode* prev = nullptr;
        int min_crit_id = -1;
        int id = 0;
        int prev_crit=-1;
        int min_dist = INT_MAX;
        for(ListNode* cur = head; cur->next; cur = cur->next){
            if(prev){
                if((cur->val > prev->val && cur->val > cur->next->val) || (cur->val < prev->val && cur->val < cur->next->val)){
                    if(prev_crit!=-1) min_dist = min(min_dist, id - prev_crit);
                    if(min_crit_id == -1) min_crit_id = id;
                    prev_crit = id;
                } 
            }
            prev = cur;
            id++;
        }
        if(min_dist!=INT_MAX){
            ans[0] = min_dist;
            ans[1] = prev_crit - min_crit_id;
        }
        return ans;
    }
};