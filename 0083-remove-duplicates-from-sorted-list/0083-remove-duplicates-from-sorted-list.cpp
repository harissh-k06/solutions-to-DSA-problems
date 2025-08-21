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
    vector<ListNode*> uniq; //space O(n)
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head->next;
        ListNode* prev = head;
        uniq.emplace_back(prev);
        while (curr){ //time O(n)
            if (curr->val != prev->val) uniq.emplace_back(curr);
            prev = curr;
            curr = curr->next;
        }
        curr = head;
        for ( auto& node : uniq){ //O(n)
            if (node == head) continue;
            curr->next = node;
            curr= curr->next;
        }
        curr->next = nullptr;
        return head;
    }
};