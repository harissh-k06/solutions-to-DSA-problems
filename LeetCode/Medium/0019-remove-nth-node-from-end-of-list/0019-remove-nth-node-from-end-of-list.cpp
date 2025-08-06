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
        int size = 0;
        ListNode* temp = head;
        while (temp){
            size++;
            temp = temp -> next;
        }
        delete temp;
        if (size == n){
            ListNode* toDel = head;
            head = head->next;
            delete toDel;
            return head;
        }
       
        ListNode* prev = head;
        for (int i = 1 ; i <= size - n - 1 ; i++){
            prev = prev->next;
        }

        ListNode* toDel = prev->next;
        prev->next = toDel->next;
        delete toDel;
        return head;
    }
};
