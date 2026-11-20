class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() <= 10) return ans;

        // 2-bit encoding: A=0, C=1, G=2, T=3
        auto encode = [](char c) -> int {
            switch (c) {
                case 'A': return 0;
                case 'C': return 1;
                case 'G': return 2;
                default:  return 3;
            }
        };

        // Total possible 10-letter DNA strings = 4^10 = 2^20 = 1,048,576
        vector<uint8_t> seen(1 << 20, 0);
        int hash = 0;
        const int mask = (1 << 20) - 1;

        for (int i = 0; i < (int)s.size(); ++i) {
            hash = ((hash << 2) | encode(s[i])) & mask;
            if (i >= 9) {
                if (seen[hash] == 1) {
                    ans.push_back(s.substr(i - 9, 10));
                    seen[hash] = 2;
                } else if (seen[hash] == 0) {
                    seen[hash] = 1;
                }
            }
        }

        return ans;
    }
};
