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
        int count =0;
        ListNode* tail = head;
        while(tail) {
            count++;
            tail=tail->next;
        };
        if (n == count) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int numberFront = count-n;
        ListNode* prev=nullptr;
        ListNode* active=head;
        while(numberFront) {
            numberFront--;
            prev=active;
            active=active->next;
        }
        prev->next = active->next;
        active->next=nullptr;
        return head;
    }
};
