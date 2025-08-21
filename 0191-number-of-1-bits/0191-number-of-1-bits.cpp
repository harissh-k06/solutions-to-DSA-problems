class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while ( n !=1 && n!= 0){
            count = n%2 == 0 ? count : count+1;
            n  = n/2;
        }
        if (n) count++;
        return count;
    }
};