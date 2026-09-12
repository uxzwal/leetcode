class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1000; i <= n; i++) {
            if (i >= 1000000) ans += 2;
            else ans += 1;
        }
        return ans;
    }
};