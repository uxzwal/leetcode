class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; ++i) {
            // Create a row of size (i + 1) filled with 1s
            vector<int> row(i + 1, 1);
            
            // Fill in the middle elements using the previous row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            // Add the completed row to our triangle
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
