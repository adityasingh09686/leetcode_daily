class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq){
        int n = seq.size();
        int s = 0;
        int a = 0;
        int b = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                s++;
                if(s%2!=0){
                    ans.push_back(0);
                    a++;
                }
                else{
                    ans.push_back(1);
                    b++;
                }
            }
            else{
               if(s%2!=0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(1);
                }
                s--;
            }
        }

        return ans;
    }
};