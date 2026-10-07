class Solution {
public:
    set<string> ans;

    bool xham(string s) {
        int balance = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                balance++;

            else if (s[i] == ')')
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

    void helper(string& o, string& s, int idx, int a, int b, int balance) {
        if (balance < 0) {
            return;
        }

        if (idx == s.size()) {
            if (a == 0 && b == 0 && balance == 0) {
                ans.insert(o);
            }
            return;
        }

        
        if (s[idx] == '(') {
            o.push_back('(');
            helper(o, s, idx + 1, a, b, balance + 1);
            o.pop_back();
            if (a > 0) {
                helper(o, s, idx + 1, a - 1, b, balance);
            }
        } else if (s[idx] == ')') {
            o.push_back(')');
            helper(o, s, idx + 1, a, b, balance - 1);
            o.pop_back();

            if (b > 0) {
                helper(o, s, idx + 1, a, b - 1, balance);
            }
        } else {
            o.push_back(s[idx]);
            helper(o, s, idx + 1, a, b, balance);
            o.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                a++;
            } else if (s[i] == ')') {
                if (a > 0) {
                    a--;
                } else {
                    b++;
                }
            }
        }

        string o = "";
        helper(o, s, 0, a, b, 0);
        vector<string> x;
        int maxi = INT_MIN;
        for (auto& p : ans) {
            maxi = max(maxi, (int)p.size());
        }

        for (auto& p : ans) {
            if (p.size() == maxi) {
                x.push_back(p);
            }
        }
        return x;
    }
};