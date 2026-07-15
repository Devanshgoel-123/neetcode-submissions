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
        ListNode* temp1 = l1;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        ListNode* temp2 = l2;
        int carryOver =0;
        while(temp1!= nullptr || temp2!=nullptr) {
            int val = carryOver;
            if (temp1) {
                val += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2) {
                val += temp2->val;
                temp2 = temp2->next;
            }
            carryOver = val / 10;
            int netValue = val % 10;
            tail->next = new ListNode(netValue);
            tail = tail->next;
        }
        if(carryOver) {
            tail->next = new ListNode(carryOver);
        }
        return dummy->next;
    }
};
