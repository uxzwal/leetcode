class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();
        
        if (n < totalLen) return result;
        
        unordered_map<string, int> wordFreq;
        for (const string& w : words) wordFreq[w]++;
        
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;
            
            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;
                    
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    if (count == wordCount) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
