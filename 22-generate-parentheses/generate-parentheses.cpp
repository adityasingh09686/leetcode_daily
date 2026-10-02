class Solution {
    private:
    void l(std::vector<std::string>& vec, std::string s, int n, int x, int y) {

    if (x == n && y == n) {
        vec.push_back(s);
        return;
    }

    if (x < n) {
        l(vec, s + '(', n, x+ 1, y);
    }

    if (y < x) {
        l(vec, s + ')', n, x, y+ 1);
    }
}
public:
    vector<string> generateParenthesis(int n) {
    std::vector<std::string> vec;
    std::string s = "";
    int x = 0; 
    int y = 0; 

    l(vec, s, n, x, y);

    return vec;
    }
};