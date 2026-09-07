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
class Compare {
   public:
    bool operator()(ListNode* a, ListNode* b) {
        if (a->val > b->val) return true;
        return false;
    }
};

class Solution {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode*> curr;
        for (const auto& ll : lists) {
            if (ll) curr.push_back(ll);
        }
        ListNode* res = nullptr;
        ListNode* head = res;

        // Step 1: Push the initial head of each non-empty list into the heap
        for (auto& ll : curr) {
            if (ll) {
                minHeap.push(ll);
                // MISSED 1: Do not advance ll = ll->next here; advancing here only
                // skips elements and does not push them in sorted order.
            }
            // MISSED 2: erase(curr, ll) is invalid syntax on std::vector and causes
            // iterator invalidation during iteration.
            // MISSED 3: The inner "while (minHeap.size() > k)" never triggers here
            // because curr.size() is at most k.
        }

        // Step 2: Pop smallest node, link it, and push its next node
        while (!minHeap.empty()) {
            if (!res) {
                res = minHeap.top();
                head = res;
            } else {
                res->next = minHeap.top();
                res = res->next;
            }
            minHeap.pop();

            // KEY ADDITION: Feed the next node from the consumed list back to the heap
            if (res->next) {
                minHeap.push(res->next);
            }
        }
        return head;
    }
};