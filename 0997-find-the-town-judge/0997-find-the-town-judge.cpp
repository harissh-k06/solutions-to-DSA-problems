class Solution {

private:
    unordered_map<int , unordered_set<int>> trustMap;
    unordered_set<int> nonJudgepeople;
    void populateTrustMap(vector<vector<int>>& trust){
        for (const auto& pair : trust){
            trustMap[pair[0]].insert(pair[1]);
        }
    }

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //if (trust.size() < n) return -1; 
        if (trust.size() == 0){
            if (n == 1 ) return 1;
            else return -1;
        }

        for (const auto& pair : trust){
            nonJudgepeople.insert(pair[0]);
        }

        if (nonJudgepeople.size() < n -1 ) return -1;

        unordered_set<int> uniqueTrustingPeople ;
        for (const auto& pair : trust){
            uniqueTrustingPeople.insert(pair[0]);
        }
        int judge = -1;
        populateTrustMap(trust);
        for (int i = 1 ; i<=n ; i++){
            if (nonJudgepeople.find(judge) != nonJudgepeople.end()) return -1;

            if (uniqueTrustingPeople.find(i)==uniqueTrustingPeople.end()){
                judge = i;
                break;
            }
        }   
        
        for (const auto& pair : trust){
            if (trustMap[pair[0]].find(judge)==trustMap[pair[0]].end()) return -1;
        }
        return judge;

    }
};