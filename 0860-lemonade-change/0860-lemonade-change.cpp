class Solution {

private:
    unordered_map<int , int> billNotes;
    void addNote(int note){
        billNotes[note]++;
    }


    void removeNote(int note){
        billNotes[note]--;
    }

public:
    bool lemonadeChange(vector<int>& bills) {
        for (const auto& bill : bills){
            if (bill == 5) addNote(bill);
            else{
                addNote(bill);
                int changeToGive = bill - 5;
                while (billNotes[20]>=1 && changeToGive >=20){
                    changeToGive-=20;
                    removeNote(20);
                }

                while (billNotes[10]>=1 && changeToGive >=10){
                    changeToGive-=10;
                    removeNote(10);
                }

                while (billNotes[5]>=1 && changeToGive >=5){
                    changeToGive-=5;
                    removeNote(5);
                }
                if (changeToGive != 0) return false;
            }
        }
        return true;
    }
};