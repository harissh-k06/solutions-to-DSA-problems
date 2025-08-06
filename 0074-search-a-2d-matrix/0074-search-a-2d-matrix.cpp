class Solution {

private:

    bool binarySearch(vector<int> arr ,const int target){
        int low =  0 , high = arr.size() -1;
        while (low  <= high){
            int mid = (low + high) / 2;
            if (arr[mid] == target ) return true;
            else if (arr[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }

        }
        return false;
    }



public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() ; 
        int cols = matrix[0].size();
        for (int i = 0 ; i < rows ; i++){
            vector<int> arr = matrix[i];
            if (target >= arr[0] && target<=arr[cols - 1])
                return binarySearch(arr , target);
        }
        return false;
    }
};