class Solution {

private:
    char xOR(char a  , char b){
        return a==b ? '0' : '1';
    }

    char carryGenerator(char a , char b , char c){
        int noOf1 = 0;
        if (a == '1') noOf1++;
        if (b == '1') noOf1++;
        if (c == '1') noOf1++;
        return (noOf1 >=2) ? '1' : '0';
    }

public:
    string addBinary(string a, string b) {
        int lena = a.length() , lenb = b.length();
        int i = lena - 1 , j = lenb - 1;

        string ans = "";
        int carry = '0';
        while (i >= 0 && j>=0){
            // carry + a + b
            char no1= a[i] , no2 = b[j];
            char binNo = xOR(carry , no1);  //  0 1 1 or 1 1 1 or 1 0 1
            binNo = xOR(binNo , no2); 
            ans+=binNo;
            carry = carryGenerator(carry , no1, no2);
            i-- ; j--;
        }

        while (i>=0){
            char no1 = a[i];
            char binNo = xOR(carry , no1);
            ans+=binNo;
            carry = carryGenerator(carry , no1 , '0');
            i--;
        }

        while (j>=0){
            char no2 = b[j];
            char binNo = xOR(carry , no2);
            ans+=binNo;
            carry = carryGenerator(carry , no2 , '0');
            j--;
        }

        if (carry == '1'){
            ans+=carry;
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};