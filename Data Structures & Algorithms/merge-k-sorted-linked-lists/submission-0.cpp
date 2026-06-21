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
    #include<queue>
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node's data
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            } 
        }
        ListNode* finalhead=new ListNode();
        ListNode* Current=finalhead;
        while(!pq.empty()) {
            ListNode* temp=pq.top();
            pq.pop();
            Current->next=new ListNode(temp->val);
            Current=Current->next;
            if(temp->next != NULL) {
                pq.push(temp->next);
            }
        }
        return finalhead->next;
    }
};