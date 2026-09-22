class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            string s = words[i];
            if (s[0] == pref[0]) {
                string t = s.substr(0,m);
                if(t==pref){
                    ans++;
                }
            }
        }

        return ans;
    }
};