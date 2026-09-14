class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Non-overlap condition: rec1 is completely left/right/above/below rec2
        bool noOverlap = rec1[2] <= rec2[0] ||   // rec1 left of rec2
                         rec2[2] <= rec1[0] ||   // rec1 right of rec2
                         rec1[3] <= rec2[1] ||   // rec1 below rec2
                         rec2[3] <= rec1[1];     // rec1 above rec2
        return !noOverlap;
    }
};