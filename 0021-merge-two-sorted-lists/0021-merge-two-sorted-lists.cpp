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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;

        while (t1 && t2) {
            int digit;
            if (t1->val <= t2->val) {
                digit = t1->val;
                t1 = t1->next;
            } else {
                digit = t2->val;
                t2 = t2->next;
            }

            ListNode* newNode = new ListNode(digit);
            prev->next = newNode;
            prev = newNode;
        }

        while (t1) {
            ListNode* newNode = new ListNode(t1->val);
            prev->next = newNode;
            prev = newNode;
            t1 = t1->next;
        }

        while (t2) {
            ListNode* newNode = new ListNode(t2->val);
            prev->next = newNode;
            prev = newNode;
            t2 = t2->next;
        }

        return dummy->next;
    }
};
