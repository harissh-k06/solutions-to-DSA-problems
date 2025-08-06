
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.length(), bLen = b.length();
        string answer;
        char c = '0'; // carry as char
        int indexA = aLen - 1, indexB = bLen - 1;
        bool flag = false;

        // Main loop
        while(indexA >= 0 && indexB >= 0){
            char bita = a[indexA];
            char bitb = b[indexB];
            char xor1 = xOR(c, bita);
            char result = xOR(xor1, bitb);
            answer += result;

            // Update the carry (flag)
            flag = carryExists(c, bita, bitb);
            c = (flag ? '1' : '0');
            indexA--;
            indexB--;
        }

        // Leftover in a
        while (indexA >= 0){
            char bita = a[indexA];
            char result = xOR(c, bita);
            answer += result;

            flag = carryExists(c, bita, '0');
            c = (flag ? '1' : '0');
            indexA--;
        } 

        // Leftover in b
        while (indexB >= 0){
            char bitb = b[indexB];
            char result = xOR(c, bitb);
            answer += result;

            flag = carryExists(c, bitb, '0');
            c = (flag ? '1' : '0');
            indexB--;
        } 

        // Final carry
        if (c == '1') answer += '1';

        reverse(answer.begin(), answer.end());
        return answer;
    }

private:
    // XOR for two chars
    char xOR(char a, char b){
        return (a == b) ? '0' : '1';
    }

    // Carry for THREE bits: true if at least two of the bits are '1'
    bool carryExists(char a, char b, char d){
        int cnt = (a == '1') + (b == '1') + (d == '1');
        return cnt >= 2;
    }
};
