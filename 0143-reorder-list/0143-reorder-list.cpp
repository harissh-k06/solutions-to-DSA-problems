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

private:
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head ? head -> next : nullptr; // this is the way to do if we want slow to point at the end of first half
        //here we dont want beggining of second half as linked list is foward we can always get next info but it is very diffidult to get the info of prev
        //so we always value prev more than first
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* head2 = reverseList(mid->next);
        mid->next = nullptr; //breaking the two halves
        ListNode* curr1 = head; ListNode* curr2 = head2;
        bool flag = true; //flag is true if we are processing first half
        while (curr1 && curr2){
            if (flag){
                ListNode* temp = curr1 -> next;
                curr1 -> next = curr2;
                curr1 = temp;
            }
            else{
                ListNode* temp = curr2 -> next;
                curr2->next = curr1;
                curr2 = temp;
            }
            flag = !flag;
        }
    }
};
