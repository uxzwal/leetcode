class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int maxPts = 1;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopes;
            int localMax = 0;
            
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy);
                }
                
                string key = to_string(dx) + "_" + to_string(dy);
                localMax = max(localMax, ++slopes[key]);
            }
            
            maxPts = max(maxPts, localMax + 1);
        }
        
        return maxPts;
    }
};
