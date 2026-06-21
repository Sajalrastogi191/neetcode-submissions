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
        int length = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            curr = curr->next;
            length++;
        }

        int l = length - n-1;
        curr = head;
        if(l == -1) return head->next;
        while(l--) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
        return head;
    }
};
