class Compare{
    public:
        bool operator()(pair<char , int> taskA , pair<char,int> taskB){
            if (taskA.second < taskB.second) return true;
            return false;
        }
};


class Solution {

private:
    priority_queue<pair<char,int> , vector<pair<char , int>> , Compare> pq;
    unordered_map<char , int> freq;
    queue<pair<char , int>> waitingList;

    void populateFreq(vector<char>& tasks){
        for (char task : tasks){
            freq[task]++;
        }
    }

    void populatePQ(){
        for (const auto& [taskName , freqOfTask] : freq){
            pq.push({taskName , freqOfTask});
        }
    }

public:
    int leastInterval(vector<char>& tasks, int n) {
        populateFreq(tasks);
        populatePQ();
        int time = 0 ;
        while (pq.size() > 0 || waitingList.size() > 0){
            if (waitingList.size()> 0 ){
                pair<char, int> firstWaitingTask = waitingList.front();
                while (!waitingList.empty() && firstWaitingTask.second <= time){
                    pq.push({firstWaitingTask.first , freq[firstWaitingTask.first]});
                    waitingList.pop();
                    firstWaitingTask = waitingList.front();
                }
            }   
            if (pq.size() > 0){
                pair<char , int> chosenTask = pq.top();
                pq.pop();
                freq[chosenTask.first]--;
                if (freq[chosenTask.first])
                    waitingList.push({chosenTask.first , time + n + 1});
            }
            time++;
        }
        return time;
    }
};