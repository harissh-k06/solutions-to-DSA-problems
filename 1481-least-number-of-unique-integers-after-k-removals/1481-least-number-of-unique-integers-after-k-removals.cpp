
class Solution {
public:
    unordered_map<int,int> count;
    

    void findCount(vector<int>& arr){
        for (auto c : arr){
            count[c]++;
        }
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        findCount(arr);
        priority_queue<int , vector<int> , greater<int>> pq; 

        for (auto& c : count){
            pq.push(c.second);
        }

        while (!pq.empty() && pq.top() <= k ){
            k-=pq.top();
            pq.pop();
        }

        return pq.size();

    }       
};