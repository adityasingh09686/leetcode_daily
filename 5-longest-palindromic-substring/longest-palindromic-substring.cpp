class Solution {
public:
    /// expand around the center bf
    int maxlen = 0;
    int start = 1;

    void expand(string& s,int a,int b){
        while(a>=0 && b<s.size() && s[a] == s[b]){
            if((b-a+1)>maxlen){
                maxlen = (b-a+1);
                start = a;
            }
            a--;
            b++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }

        return s.substr(start,maxlen);
    }
};