class Solution 
{

private:

unordered_map<char,char> openClose;

    bool isOpen(char c){
        return (c=='(' || c=='[' || c=='{');
    }

public:

    Solution(){
        openClose = {
            {'(' , ')'},
            {'[' , ']'},
            {'{' , '}'}
        };
    }

    bool isValid(string s) {
        int len = s.length();
        if (len == 0) return true;

        if (len%2!=0) return false;

        stack<char> trackOpenPara;

        for (int i = 0 ; i < len ; i++){
            char currentChar = s[i];
            if (isOpen(currentChar)){
                trackOpenPara.push(currentChar);
            }
            else{
                if (currentChar == openClose[trackOpenPara.top()]){
                    trackOpenPara.pop();
                    continue;
                }
                else{
                    return false;
                }
            }

        }
        return trackOpenPara.empty();
    }
};