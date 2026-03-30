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
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* i = l1;
        ListNode* j = l2;
        ListNode* res = new ListNode ();
        ListNode* head3 = res;
        ListNode* prev = new ListNode();
        int c = 0;
        while (i!= nullptr && j!= nullptr){
            int sum =  i->val + j-> val + c;
            int s = sum % 10 ;
            c = sum / 10 ;
            res-> val = s;
            ListNode* next = new ListNode();
            res-> next = next;
            prev = res;
            res = next;
            i = i-> next; j = j-> next;
        }   

        
        while (i!=nullptr){
            res->val = (i-> val + c) % 10;
            c = ( i->val + c ) / 10;
            ListNode* next = new ListNode();
            res-> next = next;
            prev = res;
            res = next;
            i = i-> next;
        }
        
        while(j!= nullptr){
            res->val = (j-> val + c) % 10;
            c = ( j->val + c ) / 10;
            ListNode* next = new ListNode();
            res-> next = next;
            prev = res;
            res = next;
            j = j->next;
        }

        if (c){
            res->val = c;
        }

        else{
            prev-> next = nullptr;
        }

        return head3;

    }
};