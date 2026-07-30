class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            mp[word[i]]++;
        }
        vector<pair<int, pair<char, int>>> vec;
        int k = 1;
        for (auto& p : mp) {
            int next = k + 1;
            if (next > 9) {
                next = 2;
            }
            
            vec.push_back({next, {p.first, p.second}});
            k = next; 
        }

        int ans = 0;
        map<int, int> o;
        for (int i = 0; i < vec.size(); i++) {
            int key = vec[i].first;
            char x = vec[i].second.first;
            int y = vec[i].second.second;
            o[key]++;
        }

        for (auto& p : o) {
            int count = p.second; 
            ans += (count * (count + 1)) / 2; 
        }
        
        return ans;

        return ans;
    }
};