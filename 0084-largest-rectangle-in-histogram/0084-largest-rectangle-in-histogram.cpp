class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> st;
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.back()] > h) {
                int height = heights[st.back()];
                st.pop_back();
                int width = st.empty() ? i : i - st.back() - 1;
                ans = max(ans, height * width);
            }
            st.push_back(i);
        }
        return ans;
    }
};