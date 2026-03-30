class Solution {
public:
    int minLength(string s) {
        string stack = ""; 
        
        for (char c : s) {
            if (!stack.empty()) {
                if ((stack.back() == 'A' && c == 'B') || 
                    (stack.back() == 'C' && c == 'D')) {
                    stack.pop_back(); // Remove the matching prefix
                    continue;         // Don't add the current char to stack
                }
            }
            stack.push_back(c); // No match? Add current char to stack
        }
        
        return stack.length();
    }
};