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
    void reorderList(ListNode* head) {
        
        vector<ListNode*> nodePointers;
        ListNode* curr = head;

        while(curr!= nullptr){
            nodePointers.push_back(curr);
            curr = curr->next;
        }

        vector<ListNode*> ans;
        ans.push_back(nodePointers[0]);
        int size = nodePointers.size();
        
        for(int i =1; i<= size/2; i++){
            if(i == size/2){
                if((size-1)%2!=0){
                ans.push_back(nodePointers[i]);
                continue;
                }
            }
            ans.push_back(nodePointers[size-i]);
            ans.push_back(nodePointers[i]);
        }

        ListNode* prev = ans[0];

        for(int i=1; i<size; i++){
            prev->next = ans[i];
            prev = ans[i];
        }
        prev->next = nullptr;
    }
};
