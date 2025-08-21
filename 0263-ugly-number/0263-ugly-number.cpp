class Solution {
public:
    bool isUgly(int n) {
        if (!n) return false;
        int temp = n;
        while (temp%5 == 0 ){
            temp = temp/5;
        }
        while (temp%3 == 0){
            temp = temp/3;
        }
        while (temp%2 == 0){
            temp = temp / 2;
        }

        return temp == 1;
    }
};