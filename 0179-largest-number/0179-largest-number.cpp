class Compare{
    public:

    bool operator() (const string& a , const string& b){
        if( (a + b) < (b + a)) return true;
        else return false;
    }
};


class Solution {

private:
    priority_queue<string , vector<string> , Compare> pq;

public:
    string largestNumber(vector<int>& nums) {
        vector<string> toS;
        bool isAllZero = true;
        for (int num : nums){
            toS.push_back(to_string(num));
            if (!(isAllZero && num == 0)) isAllZero = false; 
        }
        if (isAllZero) return "0";
        
        for (string num : toS){
            pq.push(num);
        }
        string res = "";
        while (!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};