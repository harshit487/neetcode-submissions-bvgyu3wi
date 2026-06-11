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
        if(head == NULL) return head;

        int size = 0;
        
        ListNode* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        int k = size - n;
        temp = head;
        if(k == 0)
        {
            head = head->next;
            temp->next = NULL;
            delete(temp);
            return head;
        }
        ListNode *curr = head;
        while(k--)
        {
           temp = curr;
           curr = curr->next; 
        }
        temp->next = curr->next;
        curr->next = nullptr;
        delete(curr);

        return head;
    }
};
