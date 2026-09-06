class Solution {

private:
    int findRow(vector<vector<int>>& grid , int target){
        int low = 0 , high = grid.size()-1;
        while (low <= high){
            int mid = (high - low)/2 + low;
            if (target>=grid[mid][0] && target<=grid[mid][grid[0].size()-1]) return mid;
            else if (target < grid[mid][0]) high = mid - 1;
            else if (grid[mid][grid[0].size()-1]<target) low = mid+1;
        }
        return -1;
    }

    int findTarget(vector<int>& arr, int target){
        int low = 0 , high = arr.size()-1;
        while (low<=high){
            int mid = (high - low) / 2 + low;
            if (arr[mid]==target) return mid;
            else if (arr[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = findRow(matrix , target);
        if (r==-1) return false;
        return !(findTarget(matrix[r] , target)==-1);

    }
};
