class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> result(total);
        for (int i = 0; i < total; ++i) {
            result[i] = i ^ (i >> 1);
        }
        return result;
    }
};
