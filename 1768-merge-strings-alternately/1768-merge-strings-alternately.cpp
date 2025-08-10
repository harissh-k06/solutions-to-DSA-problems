class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        string merged = "";
        int i = 0 , j = 0 , k = 0;
        while ( i < len1 && j<len2){
            if ( k % 2 == 0) {
                merged+=word1[i];
                i++;
            }
            else{
                merged+=word2[j];
                j++;
            } 
            k++;
        }   
        while (i< len1){
            merged+=word1[i++];
        }

        while (j < len2){   
            merged+=word2[j++];
        }
        return merged;
    }
};