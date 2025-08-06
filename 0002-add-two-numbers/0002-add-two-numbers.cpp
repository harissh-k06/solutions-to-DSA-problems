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
        ListNode* traverseL1 = l1;
        ListNode* traverseL2 = l2;
        int carry = 0 ;
        ListNode* prev =nullptr;
        ListNode* res = prev;
        while (traverseL1 || traverseL2 || carry){
            int sum = carry;
            if (traverseL1){
                sum+= traverseL1->val;
            }
            if (traverseL2){
                sum+=traverseL2->val;
            }
            int digit = sum%10;
            ListNode* newNode = new ListNode(digit);
            if (!prev){
                prev = newNode;
                res = newNode;
            }
            else{
                prev->next = newNode;
                prev = newNode;
            }
            carry = sum>= 10 ? 1 : 0;
            if (traverseL1) traverseL1 = traverseL1->next;
            if (traverseL2) traverseL2 = traverseL2->next;
        }
        return res;
    }
};
