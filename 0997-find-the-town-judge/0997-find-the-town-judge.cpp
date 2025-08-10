class Solution {

private:
    unordered_map<int, int> inDegree;  // they trust this guy
    unordered_map<int, int> outDegree; // this guy  trusts someone
    // person -> [inDegree , outdegree]
    /*
        For judge -> inDegree = n - 1 outDegree = 0
        For others -> inDegree <=n-1 outDegree>=1
    */
    void populateMap(vector<vector<int>>& trust) {
        for (const auto& pair : trust) {
            inDegree[pair[1]]++;
            outDegree[pair[0]]++;
        }
    }

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int judge = -1;
        populateMap(trust);
        for (int i= 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                judge = i;
                break;
            } else
                continue;
        }
        return judge;
    }
};
