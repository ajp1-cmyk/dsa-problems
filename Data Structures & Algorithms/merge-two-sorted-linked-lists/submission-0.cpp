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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* current = new ListNode();
        ListNode* head = current;

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

            
        if(list1->val < list2->val){
            current->val = list1->val;
            list1 = list1->next;
        }else{
            current->val = list2->val;
            list2 = list2->next;
        }

        while(list1 != nullptr && list2 != nullptr){
            
            if(list1->val < list2->val){
                    current->next = new ListNode(list1->val);
                    list1 = list1->next;
            }else{
                    current->next = new ListNode(list2->val);
                    list2 = list2->next;  
            }

            current = current->next;
        }   


        while(list1 != nullptr){
            current->next = new ListNode(list1->val);
            list1 = list1->next;
            current = current->next;
        }

        while(list2 != nullptr){
            current->next = new ListNode(list2->val);
            list2 = list2->next;
            current=current->next;
        }

        return head;
    }
};
