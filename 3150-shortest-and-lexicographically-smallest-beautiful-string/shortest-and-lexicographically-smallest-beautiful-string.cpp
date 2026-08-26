class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        int l = 0, r = 0;
        int ones = 0;
        // if (s[l] == '1') {
        //     ones++;
        // }

        string ans = "";

        for (r = 0; r < n; r++) {
            if (s[r] == '1') {
                ones++;
            }

            while (ones > k) {
                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }

            if (ones == k) {
                while (l <= r && s[l] == '0') {
                    l++;
                }
                string x = s.substr(l, r - l + 1);
                if (ans == "" || x.length() < ans.length() ||
                    (x.length() == ans.length() && x < ans)) {
                    ans = x;
                }
            }
        }

        // if the ones is equal to the k

        return ans;
    }
};