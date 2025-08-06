class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        int size = nums.size();
        vector<int> result;
        for (int i = 0; i < size; i++) {
            hashMap[nums[i]] = i;
        }
        for (int i = 0; i < size; i++) {
            int newTarget = target - nums[i];
            if (hashMap.find(newTarget) != hashMap.end() &&
                hashMap[newTarget] != i) {
                result.push_back(i);
                result.push_back(hashMap[newTarget]);
                break;
            }
        }
        return result;
    }
};