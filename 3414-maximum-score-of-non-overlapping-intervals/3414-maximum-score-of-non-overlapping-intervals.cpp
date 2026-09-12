class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // {start, end, weight, originalIndex}
        vector<array<long long,4>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        
        vector<long long> starts(n);
        for (int i = 0; i < n; i++) starts[i] = arr[i][0];
        
        // dp[i][k] = {maxScore, chosenIndices}
        vector<vector<pair<long long, vector<int>>>> dp(n+1, vector<pair<long long, vector<int>>>(5, {0, {}}));
        
        for (int i = n - 1; i >= 0; i--) {
            // find next interval with start > arr[i][1]
            int next = upper_bound(starts.begin(), starts.end(), arr[i][1]) - starts.begin();
            
            for (int k = 1; k <= 4; k++) {
                // Option 1: skip
                auto skipOpt = dp[i+1][k];
                
                // Option 2: take
                long long takeScore = arr[i][2] + dp[next][k-1].first;
                vector<int> takeList = dp[next][k-1].second;
                takeList.push_back((int)arr[i][3]);
                sort(takeList.begin(), takeList.end());
                
                pair<long long, vector<int>> takeOpt = {takeScore, takeList};
                
                // choose best
                if (takeOpt.first > skipOpt.first) {
                    dp[i][k] = takeOpt;
                } else if (takeOpt.first < skipOpt.first) {
                    dp[i][k] = skipOpt;
                } else {
                    // tie -> lexicographically smaller list
                    dp[i][k] = (takeOpt.second < skipOpt.second) ? takeOpt : skipOpt;
                }
            }
        }
        
        return dp[0][4].second;
    }
};