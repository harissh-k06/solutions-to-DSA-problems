class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        while(columnNumber){
            // To handle 'Z'
            columnNumber--;

            int remainder=columnNumber%26;
            ans.push_back('A'+remainder);

            columnNumber/=26;
        }

        reverse(begin(ans),end(ans));
        return ans;
    }
};