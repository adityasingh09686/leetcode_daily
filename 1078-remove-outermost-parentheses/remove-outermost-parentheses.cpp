class Solution{
public:
    string removeOuterParentheses(string s) {
    string result;
    int d = 0;

    for (int i = 0;i<s.size();i++) {
        char c =s[i];
        if (c == '(') {
            if (d > 0) {
                result += c;
            }
            d++;
        } else { 
            if (d> 1) {
                result += c;
            }
            d--;
        }
    }

    return result;
}
};