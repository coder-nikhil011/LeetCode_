class Solution {
public:
    int dp[100005][2];
    bool solve(int n, int person) {
        if (n == 0) return false;
        if(dp[n][person] != -1) return dp[n][person];

        for (int i = 1; i * i <= n; i++) {
            if (!solve(n - i * i, 1 - person)) {
                return dp[n][person] = true;
            }
        }

        return dp[n][person] = false;
    }

    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n, 1);
    }
};