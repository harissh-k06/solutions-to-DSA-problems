class Solution {
private:
    string toBin(int n){
        string bin = "";
        while (n!= 1 && n!=0){
            if (n % 2 == 0) bin+='0';
            else bin+='1';
            n/=2;
        }
        if (n == 1) bin+='1';
        while (bin.length() < 32){
            bin+='0';
        }
        reverse(bin.begin() , bin.end());
        return bin;
    }

    int toNum(string bin){
        int power = bin.length() -1;
        int num = 0;
        for (char c : bin){
            int mul = c == '1' ? 1 : 0;
            num+=pow(2,power--)*mul;
        }
        return num;
    }

public:
    int reverseBits(int n) {
        string bin = toBin(n);
        reverse(bin.begin()  , bin.end());
        return toNum(bin);
    }
};