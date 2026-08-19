class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> mp;
        for (auto &v : reservedSeats) {
            mp[v[0]].insert(v[1]);
        }
        int ans = 2 * n;
        for(auto& [rows,seats]:mp){
            bool l = false;
            bool r = false;
            bool m = false;
            for(int i=2;i<=5;i++){
                if(seats.count(i)){
                   l = true; 
                }
            }
            for(int i=4;i<=7;i++){
                if(seats.count(i)){
                   m = true; 
                }
            }
            for(int i=6;i<=9;i++){
                if(seats.count(i)){
                   r = true; 
                }
            }

            if(!l && !r){
                continue;
            }
            else if(!l || !r || !m){
                ans--;
            }
            else{
                ans-=2;
            }
        }

        return ans;
    }
};