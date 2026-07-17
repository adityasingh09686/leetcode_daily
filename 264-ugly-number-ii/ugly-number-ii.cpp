class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n,0);
        ans[0] = 1;
        int a=0,b=0,c=0;

        for(int i=1;i<n;i++){
            int next1 = ans[a]*2;
            int next2 = ans[b]*3;
            int next3 = ans[c]*5;

            int next_ugly = min(next1,min(next2,next3));
            ans[i] = next_ugly;

            if(next_ugly == next1){
                a++;
            }

            if(next_ugly == next2){
                b++;
            }

            if(next_ugly == next3){
                c++;
            }
        }

        return ans[n-1];
    }
};