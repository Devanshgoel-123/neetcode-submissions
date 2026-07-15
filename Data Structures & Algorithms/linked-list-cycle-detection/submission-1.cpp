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
    bool hasCycle(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp2 != nullptr && temp2->next != nullptr) {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
            if(temp1 == temp2 ) return true;
        }
        return false;
    }
};
