class Solution {
public:
    int minRotations(int n, string s) {
        int ans = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            int t = s[i] - '0';
            int d = abs(c-t);
            ans+=min(d,10-d);
            c = t;
        }

        int f = s[0] - '0';
        int l = s[n-1] - '0';

        // initial ans on reversing the whole string 
        // reversal -> leads to no change int the internal sum
        int t = ans - min(f,10-f) + min(l,10-l);

        for(int i=1;i<n;i++){
            int a = s[i-1]-'0';
            int b = s[i]-'0';
            int o1 = abs(a-b);
            int no1 = min(o1,10-o1);
            int o2 = abs(a-l);
            int no2 = min(o2,10-o2);

            t = min(t,ans-no1+no2);
        }

        return t;
    }
};