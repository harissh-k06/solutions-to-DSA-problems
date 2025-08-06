class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) { // edge case
            return {};
        }

        sort(intervals.begin(), intervals.end()); // correct

        vector<vector<int>> merged;
        merged.push_back(intervals[0]); 

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& lastMerged = merged.back(); 
            vector<int>& current = intervals[i]; 

            if (lastMerged[1] >= current[0]) { 
                lastMerged[1] = max(lastMerged[1], current[1]); 
            } else {
                merged.push_back(current); 
            }
        }
        return merged;
    }
};