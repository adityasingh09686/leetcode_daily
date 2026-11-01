class NumArray {
public:
    vector<int> st;
    int n;
    int x = -1;
    int y = -1;
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

    void helper(int i,int lo,int hi,int index,int value){
        if(lo == hi){
            st[i] = value;
            return ;
        }

        int mid = lo + (hi-lo)/2;

        if(index<=mid){
            helper(2*i+1,lo,mid,index,value);
        }
        else{
            helper(2*i+2,mid+1,hi,index,value);
        }

        st[i] = st[2*i+1] + st[2*i+2];
    }

    NumArray(vector<int>& nums){
        n = nums.size();
        st.resize(4*n);
        build(nums,0,0,n-1);
    }
    
    void update(int index, int val){
        helper(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        int x = getSum(0,0,n-1,left,right);
        return x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */