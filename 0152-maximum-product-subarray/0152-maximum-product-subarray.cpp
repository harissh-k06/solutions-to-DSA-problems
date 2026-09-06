class Solution {

private:
    pair<int , int> localMinMax = {1 , 1};
    int globalMax = INT_MIN;

public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0 ; i < size ; i++){
            if (nums[i] == 0){
                localMinMax = {1 , 1};
                globalMax = max(globalMax , 0);
                continue;
            }
            int a = localMinMax.first * nums[i];
            int b = localMinMax.second * nums[i];
            localMinMax.first = a < b ? a : b;
            localMinMax.first = min(localMinMax.first , nums[i]);
            localMinMax.second = a > b ? a : b;
            localMinMax.second = max(localMinMax.second , nums[i]);
            globalMax = max(globalMax , localMinMax.second);
        }
        return globalMax;
    }
};