#define ll long long
ll MOD = 1e9 + 7; 

class Solution {
public:
    ll power(ll a, ll b) {
        ll res = 1;
        while(b) {
            if(b & 1) res = res * a % MOD;   
            a = a * a % MOD;                 
            b >>= 1;
        }
        return res;
    }

    int numberOfSets(int n, int k) {
        ll ans = 1;

        for(ll i = 1; i <= 2*k; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }
};