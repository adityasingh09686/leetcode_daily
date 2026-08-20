class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string s = "";

        bool b = false;
        for(int i=n-1;i>=0;i--){
            if(!b && (num[i]-'0')%2!=0){
                s+=num[i];
                b = true;
            }
            else{
                if((num[i]-'0')%2!=0){
                    s+=num[i];
                }
                else if(b && (num[i]-'0')%2==0){
                    s+=num[i];
                }
            }
        }

        reverse(s.begin(),s.end());
        return s;
    }
};