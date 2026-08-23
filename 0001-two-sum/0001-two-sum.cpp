class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        for (int i = 0 ; i < nums.size() ; i++){
            hashMap[nums[i]] = i ;//storing the indices of each number 
        }

        for (int i = 0 ; i < nums.size() ; i++){
            int newTarget = target - nums[i];
            if (hashMap.find(newTarget)!=hashMap.end() && hashMap[newTarget]!=i){
                return vector<int>{i , hashMap[newTarget]};
            }
        }
        return vector<int>{};
    }
};