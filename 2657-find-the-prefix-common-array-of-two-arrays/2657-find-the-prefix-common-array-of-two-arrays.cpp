#include <vector>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();
        std::vector<int> C(n);
        std::vector<int> frequency(n + 1, 0);
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            // Process the element from array A
            frequency[A[i]]++;
            if (frequency[A[i]] == 2) {
                commonCount++;
            }

            // Process the element from array B
            frequency[B[i]]++;
            if (frequency[B[i]] == 2) {
                commonCount++;
            }

            // Store the current count of common elements
            C[i] = commonCount;
        }

        return C;
    }
};
