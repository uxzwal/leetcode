class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.length(), n2 = version2.length();
        
        while (i < n1 || j < n2) {
            long long v1 = 0;
            long long v2 = 0;
            
            // Extract the numeric value for version1's current segment
            while (i < n1 && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Extract the numeric value for version2's current segment
            while (j < n2 && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // Compare the segment values
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            
            // Move past the dot '.' character for the next iteration
            i++;
            j++;
        }
        
        return 0;
    }
};
