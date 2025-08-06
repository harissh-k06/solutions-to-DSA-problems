class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x==1 ) return x;
        long long i = -1; 
        long long low = 1 , high = x; 
        while (low<=high){
            long long mid = (low+high)/2;
            if ((mid*mid == x) || mid*mid < x && (mid+1)*(mid+1)>x) {
                i = mid;
                break;
            }
            else if (mid*mid > x){
                high = mid-1;
            }
            else if (mid*mid<x){
                low = mid+1;
            }
            else{
                continue;
            }
        }
        return (int)i;
    }
};