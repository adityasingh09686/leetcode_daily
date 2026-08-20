class Solution {
public:
    #define ll long long int 
    int myAtoi(string s) {
        int n = s.size();
        int b = 1;
        ll start = 0;
        
        while(start<n && s[start]==' '){
            start++;
        }

        if(start<n && (s[start]=='-' || s[start]=='+')){
            if(s[start] == '-') b = -1;
            start++;
        }


        ll ans = 0;

        for(int i = start;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                ans = ans*10 + (s[i]-'0');
                if(b * ans > INT_MAX) return INT_MAX;
                if(b * ans < INT_MIN) return INT_MIN;
            }
            else{
                break;
            }
        }
        return b*ans;
    }
};