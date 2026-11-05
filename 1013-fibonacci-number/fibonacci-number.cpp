class Solution {
public:
    int fib(int n) {
        vector<int> vec(n+2);
        vec[0] = 0;
        vec[1] = 1;
        for(int i=2;i<vec.size();i++){
            vec[i] = vec[i-1] + vec[i-2];
        }

        return vec[n];
    }
};