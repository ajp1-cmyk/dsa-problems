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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       
        
        vector<ListNode*> nodes;

        for(ListNode* curr = head; curr; curr = curr->next){
            nodes.push_back(curr);
        }   
        if(nodes.size() == n) return head->next;

        ListNode * prev = nodes[nodes.size()-n-1];
        prev->next = prev->next->next;
        return head;
    }
};
