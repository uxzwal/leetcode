#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        for (const auto& seat : reservedSeats) {
            int r = seat[0], c = seat[1];
            if (c >= 2 && c <= 9) {
                rows[r] |= (1 << (c - 2));
            }
        }
        
        int ans = (n - (int)rows.size()) * 2;
        int left_mask = 0b00001111;   // seats 2, 3, 4, 5
        int mid_mask = 0b00111100;    // seats 4, 5, 6, 7
        int right_mask = 0b11110000;  // seats 6, 7, 8, 9
        
        for (const auto& [r, mask] : rows) {
            bool left_ok = (mask & left_mask) == 0;
            bool right_ok = (mask & right_mask) == 0;
            bool mid_ok = (mask & mid_mask) == 0;
            
            if (left_ok && right_ok) {
                ans += 2;
            } else if (left_ok || right_ok || mid_ok) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
