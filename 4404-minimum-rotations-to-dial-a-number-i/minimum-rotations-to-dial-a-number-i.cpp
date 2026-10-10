class Solution {
public:
    int minRotations(string s){
        int n = s.size();
        map<int,int> mp;
        int ans = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            int t = s[i] - '0';
            int d = abs(c-t);
            ans+=min(d,10-d);
            c = t;
        }

        return ans;
    }
};