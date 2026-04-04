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
         ListNode * slow = head;
         ListNode * fast = head;

         while(fast && fast->next)
         {
            slow = slow->next;
            fast = fast->next->next;

         }

         ListNode * l2 = slow->next;
         slow->next = NULL;
         ListNode * l1 = head;

         
         ListNode *prev = NULL , *fut = NULL;
         while(l2)
         {
            fut = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = fut;

         }
         l2 = prev;
         ListNode* ans = new ListNode(0);
         ListNode* temp = ans;
         while(l1 && l2)
         {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
            temp->next = NULL;
            
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
            temp->next = NULL;

         }

         if(l1)
         {
            temp->next = l1;
         }
         temp = ans;
         ans = ans->next;
         delete temp;

         head = ans;

         




        


    }
};