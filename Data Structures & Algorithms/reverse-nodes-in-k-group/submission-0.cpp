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
        ListNode* finalhead=new ListNode(0);
        ListNode* temp2=finalhead;
        stack<ListNode*> s;
        ListNode* temp=head;
        while(temp != NULL) {
            ListNode* start = temp;
            for (int i = 0; i < k && temp; ++i) {
                s.push(temp);
                temp = temp->next;
            }
            if (s.size() == k) {
                while (!s.empty()) {
                    temp2->next = s.top();
                    s.pop();
                    temp2 = temp2->next;
                }
                temp2->next = temp; 
            } else {
                temp2->next = start;  
            }
        } 
        return finalhead->next;
    }
};
