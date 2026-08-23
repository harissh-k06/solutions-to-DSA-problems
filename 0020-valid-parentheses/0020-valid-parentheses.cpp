#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
    // Moved lookups here to simplify the class structure
    unordered_map<char, char> openClose = {
        {'(', ')'}, 
        {'{', '}'}, 
        { '[', ']'}
    };
    
public:
    bool isValid(string s) {
        stack<char> validate;
        
        for (char c : s) {
            // If it is an opening bracket, push to stack
            if (openClose.count(c)) {
                validate.push(c);
            } 
            // If it is a closing bracket
            else {
                // Check if stack is empty OR brackets do not match
                if (validate.empty() || c != openClose[validate.top()]) {
                    return false;
                }
                validate.pop(); // Pop only on a successful match
            }
        }
        // Return true only if all opening brackets were matched
        return validate.empty();
    }
};
