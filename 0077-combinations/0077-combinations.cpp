class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(n , k ,1 ,subset , res);
        return res;
    }
//nck



private:
    void dfs(int n , int k , int curr, vector<int>& subset , vector<vector<int>>& res){
        if (subset.size() == k){
            res.push_back(subset);
            return;
        }
        if (curr>n|| subset.size()>= n || subset.size() > k) return;
        int remainingNo = n - curr;         
        subset.push_back(curr);
        dfs(n , k , curr+1 , subset , res);
        
        subset.pop_back();
       
        if (subset.size() + remainingNo >=k)
            dfs(n , k , curr+1 , subset , res);
    }
};