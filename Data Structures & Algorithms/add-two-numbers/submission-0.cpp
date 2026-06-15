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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;
        int carry = 0;

        while(pl1 && pl2)
        {
            int sum = pl1->val + pl2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            pl1 = pl1->next;
            pl2 = pl2->next;
            carry = sum/10;
        }

        while(pl1)
        {
            int sum = pl1->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            pl1 = pl1->next;
            carry = sum/10;
        }

        while(pl2)
        {
            int sum = pl2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            pl2 = pl2->next;
            carry = sum/10;
        }

        while(carry)
        {
            tail->next = new ListNode(carry);
            carry /= 10;
        }
        head = head->next;
        return head;
    }
};
