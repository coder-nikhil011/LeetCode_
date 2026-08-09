class Solution {
public:
    vector<int> piles;
    int n;
    int dp[2][101][101];

    int solve(bool Alice, int i, int M) 
    {
        if (i >= n)
            return 0;
        if(dp[Alice][i][M] != -1) return dp[Alice][i][M];

        int stone = 0;
        int res = Alice ? -1 : INT_MAX;

        for (int x = 1; x <= min(2 * M, n - i); x++) 
        {
            stone += piles[i + x - 1];

            if (Alice)
                res = max(res, stone + solve(false, i + x, max(M, x)));
            else
                res = min(res, solve(true, i + x, max(M, x)));
        }

        return dp[Alice][i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        this->piles = piles;
        this->n = piles.size();
        memset(dp,-1,sizeof(dp));

        return solve(true, 0, 1);
    }
};