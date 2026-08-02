class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        sort(planks.begin(), planks.end());
        int n = planks.size();
        int ans = 0;

        unordered_map<int,int>mp;

        for(int i = 0; i<n; i++){
            mp[planks[i]]++;
            ans = max(ans, mp[planks[i]]);
            
        }

        vector<int> unq;

        for(auto it : mp){
            unq.push_back(it.first);
        }
        unordered_map<int,int> sum;

        for(int i = 0; i<unq.size(); i++){
            sum[2*unq[i]] += (mp[unq[i]]/2);
            for(int j = i+1; j<unq.size(); j++){
                sum[unq[i] + unq[j]] += min(mp[unq[i]], mp[unq[j]]);
            }
        }

        for(auto it : unq){
            int val = mp[it];
            if(sum.count(it)){
                val += sum[it];
            }
            ans = max(ans, val);
        }

        for(auto it : sum){
            ans = max(ans,it.second);
        }
        
        return ans;
    }
};