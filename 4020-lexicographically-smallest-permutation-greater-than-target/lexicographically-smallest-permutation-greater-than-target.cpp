class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> c(26,0);
        for(int i=0;i<n;i++){
            c[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            c[target[i]-'a']--;
        }

        for(int i=n-1;i>=0;i--){
            int cur = target[i] - 'a';
            c[cur]++; 
            bool  ok = true;
            for(int j=0;j<26;j++){
                if(c[j]<0){
                    ok = false;
                    break;
                }
            }

            if(!ok){
                continue;
            }

            int next = -1;
            for(int j=cur+1;j<26;j++){
                if(c[j]>0){ 
                    next = j;
                    break;
                }
            }
            if(next == -1){
                continue;
            }
            c[next]--;

            string ans = target.substr(0,i);
            ans+=char('a'+next);
            for(int j=0;j<26;j++){
                ans.append(c[j],char('a'+j));
            }

            return ans;
        }

        return "";
    }
};