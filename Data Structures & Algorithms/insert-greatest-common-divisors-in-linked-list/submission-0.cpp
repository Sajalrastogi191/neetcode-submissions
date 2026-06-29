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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr != NULL) {
            int val = gcd(curr->val,prev->val);
            ListNode* node = new ListNode(val);
            prev->next = node;
            node->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};