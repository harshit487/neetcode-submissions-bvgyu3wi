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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int sz = 0;
        while(temp)
        {
            sz++;
            temp = temp->next;
        }
        sz = sz/k;

        ListNode* first = new ListNode(0);
        first->next = head;
        head = first;

        ListNode *second , *current , *prev , *front;

        while(sz)
        {
            int x = k;
            second = first->next;
            prev = first;
            current = first->next;

            while(x)
            {
                front = current->next;
                current->next = prev;
                prev = current;
                current = front;
                x--;
            }
            first->next = prev;
            second->next = current;
            first = second;
            sz--;
        }

        first = head;
        head = head->next;
        delete(first);
        return head;
    }
};