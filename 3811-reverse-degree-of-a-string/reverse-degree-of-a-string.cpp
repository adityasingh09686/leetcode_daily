class Solution {
public:
    int reverseDegree(string s) {
        long long int a = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            cout<<((int)('z'-s[i])+1)<<" "<<(s[i]-'a'+1)<<endl;
            a = a + ((int)('z'-s[i])+1)*(i+1);
        }

        return a;
    }
};