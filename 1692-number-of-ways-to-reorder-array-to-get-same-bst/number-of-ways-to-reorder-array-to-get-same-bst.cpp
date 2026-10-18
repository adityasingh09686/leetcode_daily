class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    vector<ll> fact, invFact;

    ll power(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;
    }

    ll nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    ll dfs(vector<int>& vec){
        ll n = vec.size();
        if(n<=2){
            return 1;
        }
        vector<int> left,right;

        for(ll i=1;i<n;i++){
            if(vec[i]<vec[0]){
                left.push_back(vec[i]);
            }
            else{
                right.push_back(vec[i]);
            }
        }
        ll ways = nCr(n-1,left.size());

        ways = ways*dfs(left)%MOD;
        ways = ways*dfs(right)%MOD;
        return ways;
    }


    int numOfWays(vector<int>& nums) {
        init(nums.size());
        return (dfs(nums)-1+MOD)%MOD;
    }
};