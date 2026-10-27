class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m;i++){
            string s = "";
            for(int j=0;j<n;j++){
                s+=".";
            }
            ans.push_back(s);
        }
        for(int i=0;i<m-1;i++){
            for(int j=1;j<n;j++){
                ans[i][j] = '#';
            }
        }

        return ans;
    }
};