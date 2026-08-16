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

        if(!head) return nullptr;

        unordered_map<Node*, Node*> copy;
    
        for(Node* curr=  head; curr; curr = curr-> next){
            copy[curr] = new Node(curr->val);
        }
        

        for(Node* curr = head; curr; curr = curr->next){
            copy[curr]->next = copy[curr->next];
            copy[curr]->random = copy[curr->random];
        }
        return copy[head];

    }
};
