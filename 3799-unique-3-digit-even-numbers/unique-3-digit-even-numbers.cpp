
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> vec(10, 0);

        for (int d : digits) {
            vec[d]++;
        }

        int ans = 0;

        for (int i = 100; i <= 998; i += 2) {
            int x = i;

            int a = x % 10;
            x = x / 10;

            int b = x % 10;
            x = x / 10;

            int c = x;

            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > vec[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                ans++;
            }
        }

        return ans;
    }
};

