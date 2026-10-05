class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i, len = 0;
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }
            int numWords = j - i;
            int spaces = maxWidth - len;
            string line;
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += ' ';
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int per = spaces / (numWords - 1);
                int extra = spaces % (numWords - 1);
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int s = per + (k - i < extra? 1 : 0);
                        line += string(s, ' ');
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};