class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int no = digits.size();
        vector<int> result;
        int carry = 1; 
        for (int i = no-1 ; i>=0 ; i--){
            int sum = digits[i]+carry;
            carry = sum/10;
            int digit = sum%10;
            result.push_back(digit);
        }
        if (carry){
            result.push_back(carry);
        }
        reverse(result.begin() , result.end());
        return result;
    }
};
