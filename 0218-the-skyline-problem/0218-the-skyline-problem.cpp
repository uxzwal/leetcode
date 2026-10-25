#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Events store: {x_coordinate, height}
        // For a left edge, use negative height to sort it before a right edge if x is identical,
        // and to sort higher buildings first.
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Left edge
            events.push_back({b[1], b[2]});  // Right edge
        }

        // Sort events primarily by x-coordinate.
        // If x is the same, the negative height ensures correct processing order.
        sort(events.begin(), events.end());

        // Multiset acts as a max-heap to keep track of active heights
        multiset<int> active_heights = {0};
        vector<vector<int>> result;
        int prev_max_height = 0;

        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                // Left edge: insert the positive height into the active set
                active_heights.insert(-h);
            } else {
                // Right edge: erase one instance of this height from the active set
                active_heights.erase(active_heights.find(h));
            }

            // Get the current maximum height
            int current_max_height = *active_heights.rbegin();

            // If the maximum height changes, we found a new skyline key point
            if (current_max_height != prev_max_height) {
                result.push_back({x, current_max_height});
                prev_max_height = current_max_height;
            }
        }

        return result;
    }
};
