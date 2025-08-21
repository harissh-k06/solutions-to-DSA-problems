class Solution {
    vector<char> track;
public:
    Solution(){
        track.push_back('n');
        int start = 'A';
        for (int i = 1 ; i <=26 ; i++){
            track.push_back((char)start);
            start++;
        }

    }


    string convertToTitle(int columnNumber) {
        string title = "";
        cout<<701/26;
        int temp = columnNumber;
        while (temp > 0){
            int num = temp % 26; // --> 25 rem 25 = 
            if (num == 0){ title+='Z'; temp--; } 
            else title+=track[num];// --> Y
            temp/=26;// --> 26->1
        }
        reverse(title.begin() , title.end());
        return title;
    }
};