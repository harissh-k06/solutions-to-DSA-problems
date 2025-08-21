class Solution {
private:
    unordered_map<int , int> freq;
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
            if (freq[nums[i]] > 1 ) return true;
        } 
        return false;
    }
};