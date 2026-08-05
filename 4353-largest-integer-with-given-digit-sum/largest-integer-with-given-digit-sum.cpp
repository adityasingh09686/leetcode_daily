class Solution {
public:
    int largestInteger(int n, int s) {
        int maxi = n * 9;
        string t = "";
        if (s > maxi) {
            return -1;
        }

        while (s >= 9) {
            t += "9";
            if (s < 9) {
                break;
            }
            n--;
            s -= 9;
        }
        if (n > 0) {
            t += to_string(s);
            n--;
        }
        while (n > 0) {
            t += "0";
            n--;
        }
        return stoi(t);
    }
};