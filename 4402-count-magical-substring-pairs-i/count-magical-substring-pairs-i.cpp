class Solution {
public:
    // had to see the soln for this
    // unable to solve in contest
    int countMagicalPairs(string s){
        int n = s.size();
        long long int ans = 0;

        for(int j=0;j<n-1;j++){
            int f[26]={0};
            int d = 0;
            int c[27]={0};

            for(int i=j;i>=0;i--){
                // found a new alpha ++
                if(f[s[i]-'a'] == 0){
                    d++;
                }
                f[s[i]-'a']++;
                c[d]++;
            }
            
            memset(f,0,sizeof(f));
            d = 0;
            for(int k=j+1;k<n;k++){
                // found a new alpha ++
                if(f[s[k]-'a'] == 0){
                    d++;
                }
                f[s[k]-'a']++;
                ans+=c[d];
            }
        }
        return ans;
    }
};