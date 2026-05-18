class Solution {
public:
    // dfs will fail on larger input where each 0 must be scanned and this will ultimately reach the tle situation
    // dfs fails on 117/143 test case 
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n = s.size();
        q.push(0);
        int maxi = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(i==(n-1)){
                return true;
            }

            int start = max(i + minJump, farthest_reached + 1);
            int end = min(i + maxJump, (int)s.size() - 1);
            for(int k=start;k<=end;k++){
                if(s[k]=='0'){
                    q.push(k);
                }
            }
            maxi = max(maxi,maxJump+i);
        }

        return false;
    }
};