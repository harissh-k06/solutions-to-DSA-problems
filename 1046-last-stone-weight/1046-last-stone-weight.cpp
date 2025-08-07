class Solution {

priority_queue<int> storeStones;

public:
    int lastStoneWeight(vector<int>& stones) {
        int noOfStones = stones.size();
        for (int stone : stones){
            storeStones.push(stone);
        }

        while (storeStones.size() > 1){
            int y = storeStones.top();
            storeStones.pop();
            int x = storeStones.top();
            storeStones.pop();
            int newStone = (x<y) ? y - x : 0;
            if (newStone){
                storeStones.push(newStone);
            }
        }

        if (!storeStones.empty()){
            return storeStones.top();
        }else{
            return 0;
        }
    }
};