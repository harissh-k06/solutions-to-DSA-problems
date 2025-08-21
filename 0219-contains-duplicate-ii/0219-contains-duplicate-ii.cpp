class Solution {

private:
    unordered_map <int , int> track;
    unordered_map <int , int> count;
public:


    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        // track - { num : lastFound index}
        for (int i = 0 ; i < size ; i++){
            count[nums[i]]++;
            if (count[nums[i]] > 1) {
                int diffV = abs(track[nums[i]] - i);
                if (diffV <= k) return true;
            }
            track[nums[i]] = i;
        }
        return false;

    }
};