class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum < 1) return "";
        string res(num, '0');
        int rem = sum;
        for (int i = 0; i < num; i++) {
            int d = min(9, rem);
            res[i] = '0' + d;
            rem -= d;
        }
        if (rem > 0) return "";
        return res;
    }
};