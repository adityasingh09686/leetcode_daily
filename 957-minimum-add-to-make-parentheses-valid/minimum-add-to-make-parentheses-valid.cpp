class Solution {
public:
    long long int minAddToMakeValid(string s) {
        long long int n1 = 0;
        long long int n2 = 0;
        for(int i = 0;i<s.size();i++){
            char ch=s[i];
            if(ch=='('){
                n1++;
            }
            else if(ch==')' && n1>0){
                n1--;
            }
            else{
                n2++;
            }
        }
        return abs(n1+n2);
    }
};