class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            unordered_map<string , vector<string>> map;
            for (auto& str : strs){
                string key = str;
                sort(key.begin() , key.end());
                if (map.find(key)!=map.end()){
                    map[key].push_back(str);
                }else{
                    map[key] = {str};
                }
            }

            for (const auto& [k,v] : map){
                res.push_back(v);
            }

            return res;
    }
};