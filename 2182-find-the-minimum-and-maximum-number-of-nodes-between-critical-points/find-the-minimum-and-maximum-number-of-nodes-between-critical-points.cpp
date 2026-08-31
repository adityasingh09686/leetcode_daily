/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
private:
    vector<int> findMinMaxDifference(const vector<int>& nums) {
    

    if (nums.size() < 2) {
        return {0, 0}; 
    }

    int min_val = *min_element(nums.begin(), nums.end());
    int max_val = *max_element(nums.begin(), nums.end());
    int max_diff = max_val - min_val;

    vector<int> sorted_nums = nums; 
    sort(sorted_nums.begin(), sorted_nums.end());

    int min_diff = INT_MAX; 
    for (size_t i = 1; i < sorted_nums.size(); ++i) {
        int current_diff = sorted_nums[i] - sorted_nums[i - 1];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    return {min_diff, max_diff};
}
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head){ 
        vector<int> damn(2,-1);
        ListNode* v = head;
        int o = 0;
        while(v!=NULL){
            o++;
            v=v->next;
        }
        if(o==2){
            return damn;
        }
        vector<int> ans;
        vector<int> ans1;
        int n = 1;
        int c = 0;
        ListNode* prev = new ListNode(head->val);
        ListNode* curr = head;
        ListNode* nex = head->next;
        
        while(curr!=NULL && nex!=NULL){
            n++;
            if(prev->val < curr->val && curr->val>nex->val){
                c++;
                ans.push_back(n);
            }
            if(prev->val > curr->val && curr->val<nex->val){
                c++;
                ans.push_back(n);
            }
            prev->next = curr;
            prev=prev->next;
            curr=nex;
            nex=nex->next;
        }

        if(c==0 || c==1){
            return damn;
        }
        int  y = ans.size()-1;
        for(int i =0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
        
        return findMinMaxDifference(ans);
    }
};