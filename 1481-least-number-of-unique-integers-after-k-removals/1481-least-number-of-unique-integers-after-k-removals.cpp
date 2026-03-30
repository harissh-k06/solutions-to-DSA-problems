class Compare{
    public:
        unordered_map<int,int> count;

        Compare(unordered_map<int,int>& c) : count(c) {} 

        bool operator() (auto& a , auto& b){
            if (count[a] != count[b]) return count[a] > count[b];
            else return false;
        }


};

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
        priority_queue<int , vector<int> , Compare> pq(count); 
        vector <int> res ;

        unordered_set<int> unique;

        for (auto c : arr){
            unique.insert(c);
        }

        for (auto c : unique){
            pq.push(c);
        }
        
        while (!pq.empty() && count[pq.top()] <= k ){
            k-=count[pq.top()];
            pq.pop();
        }

        return pq.size();

    }       
};