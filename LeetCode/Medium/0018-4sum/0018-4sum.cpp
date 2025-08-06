class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        // i-3 j-2 k-1 l
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        for (int i = 0; i < size - 3; i++) {
            for (int j = i + 1; j < size - 2; j++) {
                int firstNo = nums[i];
                int secondNo = nums[j];
                long long remainingSum =
                    (long long)target -
                    ((long long)firstNo + (long long)secondNo);
                int low = j + 1, high = size - 1;
                while (low < high) {
                    long long sum = (long long)  nums[low] +(long long)  nums[high];
                    if (sum < remainingSum) {
                        low++;
                    } else if (sum > remainingSum) {
                        high--;
                    } else {
                        set.insert({firstNo, secondNo, nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (auto it : set) {
            result.push_back(it);
        }
        return result;
    }
};