class Solution {

private:


public:
    int maxArea(vector<int>& heights) {
        int left = 0 ;
        int right = heights.size()-1;
        int maxarea = 0;
        while ( left < right){
            int area = (right - left ) * min(heights[left] , heights[right]);
            maxarea = max(area , maxarea);
            if (heights[left] > heights[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxarea;
    }
};
