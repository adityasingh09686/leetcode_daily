class Solution{
private:
    bool matches(char x, char y){
        if(x=='(' && y==')'){
            return true;
        }

        if(x=='{' && y=='}'){
            return true;
        }

        if(x=='[' && y==']'){
            return true;
        }

        return false;
    }
public:
    bool isValid(string s) {
        stack<char> x;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                x.push(s[i]);
            }
            else{
            if(!x.empty()){  
                char y = x.top();
                if(matches(y,s[i])){
                    x.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            }
        }

        if(x.empty()){
            return true;
        }
        else{
            return false;
        }
    }

};