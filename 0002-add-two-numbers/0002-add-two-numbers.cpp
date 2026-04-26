class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* A = l1;  
        ListNode* B = l2;
        int c = 0; // Carry
        
        // Dummy node to anchor the start of our new list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        // We can combine all conditions into a single loop!
        while (A != nullptr || B != nullptr || c != 0) {
            int valA = (A != nullptr) ? A->val : 0;
            int valB = (B != nullptr) ? B->val : 0;
            
            // Calculate sum and carry
            int digitSum = valA + valB + c;
            int sum = digitSum % 10;
            c = digitSum / 10; // Alternatively: digitSum >= 10 ? 1 : 0
            
            // Create the new node and advance the current pointer
            curr->next = new ListNode(sum);
            curr = curr->next;
            
            // Advance A and B if they aren't null
            if (A != nullptr) A = A->next;
            if (B != nullptr) B = B->next;
        }

        // The actual result starts at the node AFTER the dummy
        ListNode* result = dummy->next;
        
        // Prevent memory leak by deleting the dummy node (best practice)
        delete dummy; 
        
        return result;
    }
};