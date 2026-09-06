class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        if (len == 1 || len == 0) return len;
        if (len == 2 && s[0] == s[1]) return 3;
        vector<vector<bool>> store(len , vector<bool>(len , false));

        int count = 0;
        for (int i = 0 ; i < len ; i++){
            store[i][i] = true;
            count++;
        }


        for (int i =0 ; i < len - 1 ; i++){
            store[i][i+1] = s[i] == s[i+1] ? true : false;
            count = s[i] == s[i+1] ? count + 1 : count;
        }

        //anything more than length 2

        int currLen = 3;
        while (currLen <= len){
            for (int i = 0 ; i <= len - currLen ; i++){
                int j = i + currLen - 1;
                if (s[i] == s[j] && store[i+1][j-1]){
                    store[i][j] = true;
                    count++;
                }
            }
            currLen++;
        }
        return count;
    }
};

