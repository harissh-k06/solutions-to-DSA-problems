/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {

private:
    unordered_map<int , int> cache;
    int findMax(int target, MountainArray &mountainArr){
        int low = 0 , high = mountainArr.length() - 1;
        while (low <= high){
            int mid = ( high - low) / 2 + low;
            int midM;
            if (cache.count(mid)){
                midM = cache[mid];
            }
            else{
                midM = mountainArr.get(mid);
                cache[mid] = midM;
            }
            
            int midL  = mid - 1 >= 0 ? mountainArr.get(mid - 1) : -1;
            int midH = mid + 1 <= mountainArr.length() - 1 ? mountainArr.get(mid + 1) : -1;
            if ( midM > midL && midM > midH) return mid;
            else if (midM > midL && midM < midH) low = mid+1;
            else if (midM < midL && midM > midH) high = mid-1;
        }
        return -1;
    }

    int binarySearch1(int target, MountainArray &mountainArr, int high){
        int low = 0;
        while (low <= high){
            int mid = (high - low) / 2  + low;
            int midV;
            if (cache.count(mid)){
                midV = cache[mid];
            }
            else{
                midV = mountainArr.get(mid);
                cache[mid] = midV;
            }
            if ( midV == target) return mid;
            else if (midV < target){
                low = mid + 1 ;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }

    int binarySearch2(int target, MountainArray &mountainArr, int low){
        int high = mountainArr.length() - 1 ;
        while (low <= high){
            int mid = (high - low) / 2  + low;
            int midV;
            if (cache.count(mid)){
                midV = cache[mid];
            }
            else{
                midV = mountainArr.get(mid);
                cache[mid] = midV;
            }
            if ( midV == target) return mid;
            else if (midV > target){
                low = mid + 1 ;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }


public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int maxIdx = findMax(target  ,mountainArr);
        int potIdx = binarySearch1(target , mountainArr ,  maxIdx);
        if (potIdx == -1){
            potIdx = binarySearch2(target , mountainArr ,  maxIdx);
        }
        return potIdx;
    }
};