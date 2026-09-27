class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int l = st.top() + 1;
                int r = i - 1;

                while (l < r) {
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }

                st.pop();
            }
        }

        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
        }

        return ans;
    }
};