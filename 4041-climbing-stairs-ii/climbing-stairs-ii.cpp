class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        
        // Step 0 par khade hone ka cost
        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            // Pichhle 3 steps (j-1, j-2, j-3) se kood kar aane ke rasta
            for (int jump = 1; jump <= 3; jump++) {
                int i = j - jump;
                if (i >= 0) {
                    int currentCost = dp[i] + costs[j - 1] + (j - i) * (j - i);
                    dp[j] = min(dp[j], currentCost);
                }
            }
        }

        return dp[n];
    }
};
