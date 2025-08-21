class Solution {

    int sumOfDigits(int num){
        int ans = 0;
        while (num > 0){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }

public:
    int addDigits(int num) {
        int temp = num;
        while (temp >=10){
            temp = sumOfDigits(temp);
        }
        return temp;
    }
};