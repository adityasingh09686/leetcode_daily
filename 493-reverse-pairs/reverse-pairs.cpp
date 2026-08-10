class Solution {
public:
    int merge_count(vector<int>& nums, int i, int j, int mid) {
        int n1 = mid - i+1;
        int n2 = j - mid;
        // basically the work of filling the shi
        vector<int> L(nums.begin() + i, nums.begin() + mid + 1);
        vector<int> R(nums.begin() + mid + 1, nums.begin() + j + 1);
        int x = 0;
        int d = mid+1;
        for (int a = i; a <= mid; a++) {
            while(d<=j && (long long)nums[a]>(long long)nums[d]*2){
                d++;
            }
            x+=(d-(mid+1));
        }
        vector<int> temp;
        int f = 0,e = 0;
        while (f< n1 && e < n2) {
            if (L[f] <= R[e]) {
                temp.push_back(L[f]);
                f++;
            } else {
                temp.push_back(R[e]);
                e++;
            }
        }

        while (f< n1) {
            temp.push_back(L[f]);
            f++;
        }

        while (e < n2) {
            temp.push_back(R[e]);
            e++;
        }

        for(int a=i;a<=j;a++){
            nums[a] = temp[a-i];
        }

        return x;
    }
    int merge(vector<int>& nums, int start, int end) {
        int i = start;
        int j = end;
        int ans = 0;
        if(i>=j){
            return 0;
        }
        int a = 0;
        int mid = i + (j-i)/2;
        a+=merge(nums,i,mid);
        a+=merge(nums,mid+1,j);
        a+=merge_count(nums,i,j,mid);
        return a;
    }
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
    }
};