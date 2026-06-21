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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre_prev = dummy;
        for(int i = 1;i<left;i++) {
            pre_prev = pre_prev->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = pre_prev->next;
        ListNode* next = NULL;
        ListNode* tail = curr;

        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        pre_prev->next = prev;
        tail->next = curr;
        return dummy->next;
    }
};