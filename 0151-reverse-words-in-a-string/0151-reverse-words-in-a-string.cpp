class Solution {
public:
    string reverseWords(string s) {
        string res, word;
        istringstream iss(s);
        vector<string> words;
        while (iss >> word) words.push_back(word);
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];
            if (i > 0) res += " ";
        }
        return res;
    }
};