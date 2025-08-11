class Solution {

private:
    string prevAnagramKey;

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        int size = words.size();
        string prevAnagramKey = words[0];
        sort(prevAnagramKey.begin() , prevAnagramKey.end());
        res.emplace_back(words[0]);
        for (int i = 1 ; i < size ; i++){
            string word = words[i];
            sort(word.begin() , word.end());
            if (word != prevAnagramKey){
                res.emplace_back(words[i]);
            }
            prevAnagramKey = word;
        }
        return res;
    }
};