class Solution {
public:
    int minOperations(int n) {
        int ops = 0;
        while (n > 0) {
            if ((n & 3) == 3) {
                n++;
                ops++;
            } else if ((n & 1) == 1) {
                n--;
                ops++;
            } else {
                n >>= 1;
            }
        }
        return ops;
    }
};
