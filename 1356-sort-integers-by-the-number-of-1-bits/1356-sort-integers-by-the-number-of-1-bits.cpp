class Compare {
public:
    // Mark as mutable so the const operator() can update the cache
    mutable unordered_map<int, int> memo;

    Compare() {
        memo[0] = 0;
    }

    int countBits(int n) const {
        if (memo.count(n)) return memo[n];
        // Recursive bit count: (n % 2) is the current bit, 
        // plus bits in the rest of the number (n >> 1)
        return memo[n] = (n % 2) + countBits(n >> 1);
    }

    bool operator()(const int& a, const int& b) const {
        int bitsA = countBits(a);
        int bitsB = countBits(b);

        if (bitsA != bitsB) {
            // We want smaller bit counts at the TOP of the result.
            // In a priority_queue, returning TRUE means 'a' has LOWER priority.
            // So if bitsA > bitsB, 'a' should be lower priority (behind 'b').
            return bitsA > bitsB;
        }
        // If bits are equal, sort by value. 
        // Larger values should have lower priority (be at the end).
        return a > b;
    }
};


class Solution {

    priority_queue<int , vector<int> , Compare > pq ;

public:

    Solution(){
        
    }

    

    vector<int> sortByBits(vector<int>& arr) {

        vector<int> res;

        for ( int c : arr){
            pq.push(c);
        }

        while (!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};