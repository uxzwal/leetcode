class Solution {
public:
    int pivotInteger(int n) {
        // Total sum of numbers from 1 to n
        int totalSum = n * (n + 1) / 2;
        
        // x must be the integer square root of totalSum
        int x = sqrt(totalSum);
        
        // Verify if totalSum is a perfect square
        if (x * x == totalSum) {
            return x;
        }
        
        return -1;
    }
};
