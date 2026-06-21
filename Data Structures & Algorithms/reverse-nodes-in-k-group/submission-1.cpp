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
        if(!head || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroup = dummy;
        while(true) {
            ListNode* kth = prevGroup;
            for(int i = 0;i<k && kth != NULL;i++) {
                kth = kth->next;
            }
            if(kth == NULL) break;

            ListNode* nextGroup = kth->next;

            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while(curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* tm = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = tm;
        }

        return dummy->next;
    }
};
