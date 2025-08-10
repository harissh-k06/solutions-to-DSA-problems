class Solution {
private:
    unordered_map<char , int> priority;

    void setPriority(const string& s){
        int prior = 1;
        for (char letter : s){
            priority[letter] = prior;
            prior++;
        }
    }

    bool checkSorted(const string& word1 , const string& word2){
        int len1 = word1.length();
        int len2 = word2.length();
        
        int minLen = min(len1 , len2);

        for (int i = 0 ; i < minLen ; i++){
            if (priority[word1[i]] == priority[word2[i]]) continue;
            else if (priority[word1[i]] < priority[word2[i]]) return true;
            else return false;
        }
        return word1.length() <= word2.length();
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        setPriority(order);
        int noOfWords = words.size();
        for (int i = 0 ; i< noOfWords-1 ; i++){
            bool flag = checkSorted(words[i] , words[i+1]);
            if (flag) continue;
            else return flag;
        }
        return true;
    }
};