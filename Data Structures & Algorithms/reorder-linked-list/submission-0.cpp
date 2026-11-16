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
        ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
      if(head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;
        ListNode* temp1 = head;
        ListNode* temp2 = reverse(newHead);
        while(temp1 != NULL && temp2 != NULL) {
            ListNode* curr1 = temp1->next;
            ListNode* curr2 = temp2->next;
            temp1->next = temp2;
            temp2->next = curr1;
            temp1 = curr1;
            temp2 = curr2;
        }
    }
};
