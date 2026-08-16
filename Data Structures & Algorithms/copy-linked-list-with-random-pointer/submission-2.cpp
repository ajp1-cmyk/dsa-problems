/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy{0};
        Node* temp = &dummy;

        unordered_map<Node*, Node*> corr_nodes;
        corr_nodes[nullptr] = nullptr;

        for(Node* curr=  head; curr; curr = curr-> next){
            temp -> next = new Node(curr->val);
            corr_nodes[curr] = temp->next;
            temp = temp->next;
        }
        temp->next = nullptr;

        temp = dummy.next;

        for(Node* curr = head; curr; curr = curr->next){
            temp->random = corr_nodes[curr->random];
            temp = temp->next;
        }
        return dummy.next;

    }
};
