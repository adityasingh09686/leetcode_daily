class Solution {
public:
    int helper(int n){
        int ans = 1;
        int t = n;
        while(t > 0){
            ans *= t % 10;
            t = t / 10;
        }
        return ans;
    }
    
    int smallestNumber(int n, int t){
        while(helper(n) % t != 0){
            n++;
        }
        return n;
    }
};