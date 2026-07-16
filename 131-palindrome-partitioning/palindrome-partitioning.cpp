class Solution {
public:
    bool checkpallin(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        if (s != t) {
            return false;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans, vector<string>& output, int start,
                string& s) {
        if (start == s.size()) {
            ans.push_back(output);
        }

        for (int i = start; i < s.size(); i++) {
            string str = s.substr(start, i - start + 1);
            if (checkpallin(str)) {
                output.push_back(str);
                helper(ans, output, i + 1, s);
                output.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> output;
        helper(ans,output,0,s);
        return ans;
    }
};