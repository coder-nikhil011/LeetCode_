class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1));
        dp[0][0] = 1;

        for (int num : nums) {
            auto ndp = dp;

            for (int x = 0; x <= mx; x++) {
                for (int y = 0; y <= mx; y++) {
                    if (dp[x][y] == 0) continue;

                    int nx = gcd(x, num);
                    int ny = gcd(y, num);

                    ndp[nx][y] = (ndp[nx][y] + dp[x][y]) % MOD;
                    ndp[x][ny] = (ndp[x][ny] + dp[x][y]) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= mx; g++)
            ans = (ans + dp[g][g]) % MOD;

        return ans;
    }
};