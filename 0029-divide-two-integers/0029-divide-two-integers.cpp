class Solution {
public:
    int divide(int x, int y) {
//due to the given limits of x and y, we dont want thereto be overflow
               long long a = (long long) x;
        long long b = (long long) y;
        
//the simple case
        if(a==INT_MIN && b==1) return INT_MIN;
        if(a==INT_MIN && b==-1) return INT_MAX;
        
        bool positive = ((a>0) == (b>0));
        a = abs(a);
        b = abs(b);
        //in usual divison we add divisor to itself several times, and add the count to quotient
        //so here in bit manp, wecan do that by left shifting b by i times => b * (2poweri)
        //i=0 => b is added to check, i=1 => 2b is added to check
        //also we need to subtract the biggest chunck first to get correct results
        long long check = 0;
        long long ans = 0;
        for(int i=31; i>=0; i--){
            if((check + (b<<i)) <= a) {
                check += (b<<i);
                ans += (1<<i);
            }
        }
        
        if(positive) return ans;
        return -ans; 
    }
};