class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size(), ans = 0;
        vector<int> h(n + 1, 0);
        for (auto& row : matrix) {
            for (int j = 0; j < n; j++)
                h[j] = (row[j] == '1') ? h[j] + 1 : 0;
            vector<int> st;
            for (int j = 0; j <= n; j++) {
                while (!st.empty() && h[st.back()] > h[j]) {
                    int height = h[st.back()];
                    st.pop_back();
                    int width = st.empty() ? j : j - st.back() - 1;
                    ans = max(ans, height * width);
                }
                st.push_back(j);
            }
        }
        return ans;
    }
};