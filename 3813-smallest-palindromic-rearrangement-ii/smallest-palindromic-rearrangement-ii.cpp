class Solution {
public:
    long long nCr(long long n, long long r, long long k_max) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (n - r < r) r = n - r;

        long long res = 1;
        for (long long i = 1; i <= r; ++i) {
            long long num = n - i + 1;
            long long den = i;
            
            long long g = std::gcd(res, den);
            long long temp_res = res / g;
            den /= g;
            
            num /= den; 
            
            if (num > 0 && temp_res > (k_max + 1) / num) {
                return k_max + 1;
            }
            res = temp_res * num;
        }
        return res;
    }

    long long final_count(long long n, vector<long long> f, long long k) {
        long long total = 1;
        for (int i = 0; i < 26; i++) {
            if (f[i] == 0) continue;
            
            long long cnt = nCr(n, f[i], k);

            if (cnt > 0 && total > (k + 1) / cnt) {
                return k + 1;
            }
            total *= cnt;
            n -= f[i];
        }
        return total;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int len = n / 2;
        vector<long long> f(26, 0);
        
        for (int i = 0; i < n; i++) {
            f[s[i] - 'a']++;
        }

        string result(n, ' ');
        int odd_count = 0;

        for (int i = 0; i < 26; i++) {
            if (f[i] % 2 == 1) {
                result[n / 2] = (i + 'a');
                odd_count++;
            }
            f[i] /= 2;
        }

        if (odd_count > 1) return "";

        long long count = final_count(len, f, k);
        if (count < k) {
            return "";
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) {
                if (f[j] > 0) {
                    f[j]--;
                    long long ways = final_count(len - 1 - i, f, k);
                    if (k <= ways) {
                        result[i] = (j + 'a');
                        break;
                    } else {
                        k -= ways;
                        f[j]++;
                    }
                }
            }
        }

        for (int i = 0; i < len; i++) {
            result[n - i - 1] = result[i];
        }

        return result;
    }
};