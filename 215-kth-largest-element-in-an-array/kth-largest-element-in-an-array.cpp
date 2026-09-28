class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            q.push(nums[i]);
        }

        for(int i=0;i<k-1;i++){
            q.pop();
        }

        return q.top();
    }
};