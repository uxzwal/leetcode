#include <vector>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate the sum of digits of a number
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        // Structure to store value, digit sum, and original index
        struct Element {
            int val;
            int digitSum;
            int origIdx;
        };
        
        std::vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], getDigitSum(nums[i]), i};
        }
        
        // Sort based on the problem criteria
        std::sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digitSum != b.digitSum) {
                return a.digitSum < b.digitSum;
            }
            return a.val < b.val;
        });
        
        // Decompose into permutation cycles to count the minimum swaps
        std::vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // Skip if already visited or already in the correct position
            if (visited[i] || arr[i].origIdx == i) {
                continue;
            }
            
            int cycleSize = 0;
            int j = i;
            
            // Traverse the current cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].origIdx;
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
