class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int twoBack  = 1 , oneBack = 2; 
        for (int i = 3 ; i <=n ; i++){  
            int current = twoBack+oneBack;
            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }
};