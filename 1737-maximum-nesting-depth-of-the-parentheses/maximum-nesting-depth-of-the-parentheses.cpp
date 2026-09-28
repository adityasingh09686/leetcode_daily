class Solution{
private:
    bool matches(char x ,char y){
        if(x=='(' && y==')'){
            return true;
        }
        return false;
    }
public:
    int maxDepth(string s){
        stack<char> st;
        int m=0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    char y = st.top();
                    if(matches(y,s[i])){
                       int z = st.size();
                       m = max(m,z);
                       st.pop(); 
                    }
                    else{
                        st.push(s[i]);
                    }
                }
                else{
                    st.push(s[i]);
                }
            }
        }

        return m;
    }
};