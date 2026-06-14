/*
// Definition for a Node.
class Node {
public:
    int val;å
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
        if(head == NULL) return NULL;

        unordered_map<Node* , Node*> m;

        Node* new_head = new Node(head->val);
        Node* temp1 = head->next;
        Node* temp2 = new_head;
        m[head] = new_head;

        while(temp1)
        {
            Node* copyNode = new Node(temp1->val);
            m[temp1] = copyNode;
            temp2->next = copyNode;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1 = head;
        temp2 = new_head;

        while(temp1)
        {
            temp2->random = m[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return new_head;
    }
};