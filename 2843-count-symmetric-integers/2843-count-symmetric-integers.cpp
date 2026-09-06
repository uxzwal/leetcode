class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        
        for (int i = low; i <= high; ++i) {
            std::string s = std::to_string(i);
            int n = s.length();
            
            // Only numbers with an even number of digits can be symmetric
            if (n % 2 == 0) {
                int half = n / 2;
                int left_sum = 0;
                int right_sum = 0;
                
                // Sum the first half and the second half
                for (int j = 0; j < half; ++j) {
                    left_sum += s[j] - '0';
                    right_sum += s[j + half] - '0';
                }
                
                if (left_sum == right_sum) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
