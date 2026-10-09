class Solution {
public:
    int minInsertions(string s){
        stack<char> st;
        int n = s.size();
        int x = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                x++;
            }
            else{
                if(x==0){
                    ans++;
                }
                else{
                    x--;
                }

                if(i+1 >= s.size()){
                    ans++;
                }
                else{
                    if(s[i+1]==')'){
                        i++;
                    }
                    else{
                        ans++;
                    }
                }
            }
        }

        return ans + x*2;
    }
};