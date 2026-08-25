class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0 || n==1) return n;
        vector<int> array;
        array.push_back(0); array.push_back(1);
        int i = 2;
        int max_Element = INT_MIN;
        while(i<n+1){
            if ((i&1) == 0){
                array.push_back(array[i / 2]);
            }else{
                array.push_back(array[i / 2] + array[i / 2 + 1]);
            }
            max_Element = array[i] > max_Element ? array[i] : max_Element;
            i++;
        }
        return max_Element;
    }
};