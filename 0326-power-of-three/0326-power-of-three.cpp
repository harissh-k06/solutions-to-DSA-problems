class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;
       if (n%3!=0) return false;
       int temp = n;
       while (temp >1){
            if (temp%3 != 0) return false;
            temp=temp/3;
       }
       return temp == 1; //O(log3 (n))
    }
};