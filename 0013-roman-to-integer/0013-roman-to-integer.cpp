class Solution {
public:
    int romanToInt(string s) {
        /*
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
        */

        unordered_map<char,int> map;
        map['I'] = 1;   map['L'] = 50;  map['M'] = 1000;
        map['V'] = 5;   map['C'] = 100;
        map['X'] = 10;  map['D'] = 500;
        int number = 0;
        for (int i = 0 ; i< s.length() ; i++){
            // XII = 12 //XIV = 14 = 10 + 5 -1
            if (map[s[i]]<map[s[i+1]] && i+1!=s.length()){
            number= number +map[s[i+1]] - map[s[i]];
            i++;
            }
            else number+=map[s[i]];
        }
        return number;
    }
};