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
        
        vector<ListNode*> nodes;
        ListNode* curr = head;

        for(ListNode* curr = head; curr; curr = curr->next){
            nodes.push_back(curr);
        }


        int left = 0;
        int right = nodes.size()-1;
        vector<ListNode*> order;

        while(left < right){
            order.push_back(nodes[left]);
            order.push_back(nodes[right]);
            left++;
            right--;
        }

        if(left==right) order.push_back(nodes[left]);


        for(int i=1; i<order.size(); i++){
            order[i-1]->next = order[i];
        }
        order[order.size()-1]->next = nullptr;
    }
};
