class Solution {
public:
    bool checkValidString(string s){
        stack<int> st;
        stack<int> st2;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]=='*'){
                st2.push(i);
            }
            else{
                if(st.empty() && st2.empty()){
                    return false;
                }
                else{
                    if(!st.empty()){
                        st.pop();
                    }
                    else if(!st2.empty()){
                        st2.pop();
                    }
                }
            }
        }
        while(!st.empty() && !st2.empty()){
        if(st.top() > st2.top())
            return false;
        st.pop();
        st2.pop();
        }
        return st.empty();
    }
};