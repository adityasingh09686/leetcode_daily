class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> vec(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vec[s[i] - 'a']++;
        }

        string ans = "";
        int x = -1;

        for (int i = 0; i < 26; i++) {
            if (vec[i] != 0) {
                if (vec[i] % 2 == 1){
                    int k = (vec[i]-1)/ 2;
                    vec[i] -= k;
                    for (int j = 0; j < k; j++) {
                        ans += (char)(i + 'a');
                    }
                    x = i;
                } else {
                    int k = vec[i] / 2;
                    vec[i] -= k;
                    for (int j = 0; j < k; j++) {
                        ans += (char)(i + 'a');
                    }
                }
            }
        }

        if (x != -1) {
            int m = 1; 
            string l = ans;
            reverse(l.begin(), l.end());
            for (int j = 0; j < m; j++) {
                ans += (char)(x + 'a');
            }
            vec[x] = 0;
            return ans + l;
        }
        string l = ans;
        reverse(l.begin(),l.end());
        
        return ans+l;
    }
};