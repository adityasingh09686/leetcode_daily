class NumArray {

public: 
    vector<int> st;
    int n;
    void build(vector<int>& arr, int i, int lo, int hi) {
        if (hi == lo) {
            st[i] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(arr, 2 * i + 1, lo, mid);
        build(arr, 2 * i + 2, mid + 1, hi);
        st[i] = st[2 * i + 1]+st[2 * i + 2];
    }

    int getSum(int i, int lo, int hi, int l, int r) {
        if (lo > r || hi < l)
            return 0;
        if (lo >= l && hi <= r)
            return st[i];
        int mid = lo + (hi - lo) / 2;
        return getSum(2 * i + 1, lo, mid, l, r) + getSum(2 * i + 2, mid + 1, hi, l, r);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        build(nums,0,0,n-1);
    }

    int sumRange(int left, int right) {
        int x = getSum(0,0,n-1,left,right);
        return x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */