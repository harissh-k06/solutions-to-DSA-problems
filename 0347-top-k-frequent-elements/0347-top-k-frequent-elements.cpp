class Compare{
    public:
        bool operator()(pair<int , int> element1 , pair<int , int> element2 ){
            if (element1.second > element2.second) return true;
            else return false;
        }
};


class Solution {
private:
    unordered_map<int , int> freq;
    priority_queue<pair<int , int> , vector<pair<int , int>> , Compare> pq;

    void populateFreq(vector<int>& nums){
        for (int num : nums){
            freq[num]++;
        }
    }  

    void populatePQ(int k){
        for (const auto& [num , v] : freq){
            pq.push({num , v});
            if (pq.size() > k){
                pq.pop();
            }
        }
    } 

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        populateFreq(nums);
        populatePQ(k);
        vector<int> answer;
        while (!pq.empty()){
            answer.emplace_back(pq.top().first);
            pq.pop();
        }
        return answer;
    }
};
