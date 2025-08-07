class Solution {

private:
    priority_queue<int , vector<int> , greater<int>> pq; 


public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int num : nums){
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};