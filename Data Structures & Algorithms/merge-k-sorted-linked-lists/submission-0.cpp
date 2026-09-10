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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        
        int k = lists.size();
        vector<int> list;
        if(k==1) return lists[0];

        for(int i=0; i<k;i++){
            ListNode* curr = lists[i];
            while(curr){
                list.push_back(curr->val);
                curr=curr->next;
            }
        }

        sort(list.begin(), list.end());
        
        ListNode* curr = dummy;
        for(int i=0; i<list.size(); i++){
            curr->next = new ListNode(list[i]);
            curr = curr->next;
        }
        return dummy->next;
    }
};
