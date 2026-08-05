class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long e) {
        long long res = 1;
        while (e) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

    long long C(int n, int r, vector<long long>& fact, vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countValidSequences(int n, int k) {
        if (n < k) return 0;

        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        long long total = C(n - 1, k - 1, fact, invFact);

        long long odd = 0;
        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = C(m + k - 1, k - 1, fact, invFact);
        }

        return (total - odd + MOD) % MOD;
    }
};