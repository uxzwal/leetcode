class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Project both rectangles onto X and Y axes separately.
        // They overlap iff BOTH 1D projections overlap.
        // 1D segments [a,b] and [c,d] overlap (positive length) iff max(a,c) < min(b,d).
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
               max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};