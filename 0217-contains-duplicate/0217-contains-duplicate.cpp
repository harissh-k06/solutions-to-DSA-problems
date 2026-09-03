class Solution {

private:
    unordered_map<int , int> freq;

public:
    bool containsDuplicate(vector<int>& nums) {
        for (int n : nums){
            if (freq[n]>=1){
                return true;
            }else{
                freq[n]++;
            }
        }
        return false;
    }
};