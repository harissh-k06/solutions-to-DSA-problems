class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple = k;
        int found = 0 ;
        while (!found){
            if (find(nums.begin() , nums.end() , multiple) == nums.end()) found = 1;
            else{
                multiple += k;
            }
        }
        return multiple;
    }
};