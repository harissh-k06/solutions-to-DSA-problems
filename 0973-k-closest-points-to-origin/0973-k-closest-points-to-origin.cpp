class Compare{
public:
    bool operator()(const vector<int>& firstPoint , const vector<int>& secondPoint){
        int firstPointDist = pow(firstPoint[0] , 2) + pow(firstPoint[1] , 2);
        int secondPointDist = pow(secondPoint[0] , 2) + pow(secondPoint[1] , 2);
        if (firstPointDist < secondPointDist){
            return true;
        }else{
            return false;
        }
    }
};


class Solution {
private:
    priority_queue<vector<int> , vector<vector<int>> , Compare> pq; 
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (const auto& point : points){
            pq.push(point);
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()){
            res.emplace_back(pq.top());
            pq.pop();
        }
        return res;
    }
};