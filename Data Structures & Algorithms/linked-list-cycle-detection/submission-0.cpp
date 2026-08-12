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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;

        if(head->next == nullptr) return false;

        ListNode* first = head;
        ListNode* second = head->next;

        while(second!= nullptr && second->next != nullptr){
            if(second == first) return true;
            first = first->next;
            second = second->next->next;
    
        }

        return false;

    }
};
