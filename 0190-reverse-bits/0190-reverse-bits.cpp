class Solution {
public:
    int reverseBits(int n) {
        uint32_t u = static_cast<uint32_t>(n);
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) | (u & 1);
            u >>= 1;
        }
        return static_cast<int>(res);
    }
};
