class Solution {
public:
    vector<string> maxNumOfSubstrings(string s){
        int n = s.size();
        vector<int> f(26,n);
        vector<int> l(26,-1);

        for(int i=0;i<n;i++){
            int c = s[i] - 'a';
            f[c] = min(f[c],i); // first occurence of the char
            l[c] = i; //  last occurence of the char
        }

        vector<pair<int,int>> vec; // for storing the pair 

        for(int c=0;c<26;c++){
            int a = f[c]; // first char
            int b = l[c]; // last char
            if(b == -1){
                continue;
            }

            bool p = false;
            for(int i=a;i<=b;i++){
                if(f[s[i]-'a']<a){
                    p = true; // not a valid shi
                    break;
                }
                b = max(b,l[s[i]-'a']);
            }

            if(!p){
                vec.push_back({a,b});
            }
        }

        sort(vec.begin(), vec.end(),
             [](const pair<int,int>& a,
                const pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prev = -1;

        for(int i=0;i<vec.size();i++){
            if(vec[i].first>prev){
                ans.push_back(s.substr(vec[i].first,vec[i].second - vec[i].first+1));
                prev = vec[i].second;
            }
        }

        return ans;
    }
};