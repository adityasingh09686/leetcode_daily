class RangeFreqQuery {
public:
    vector<map<int, int>> st;
    int n;
    void build(vector<int>& arr, int i, int lo, int hi) {
        if (hi == lo) {
            st[i][arr[lo]]++;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(arr, 2 * i + 1, lo, mid);
        build(arr, 2 * i + 2, mid + 1, hi);
        for (auto& it : st[2 * i + 1])
            st[i][it.first] += it.second;

        for (auto& it : st[2 * i + 2])
            st[i][it.first] += it.second;
    }

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    int getFreq(int i, int lo, int hi, int l, int r, int val) {
        if (lo > r || hi < l)
            return 0;
        if (lo >= l && hi <= r)
            return st[i][val];
        int mid = lo + (hi - lo) / 2;
        return getFreq(2 * i + 1, lo, mid, l, r, val) +
               getFreq(2 * i + 2, mid + 1, hi, l, r, val);
    }
    int query(int left, int right, int value) {
        int x = getFreq(0, 0, n - 1, left, right, value);
        return x;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */