class Solution {
public:
    int memo[101][101][201];

    bool validPath(vector<vector<char>>& grid, int i, int j, int bal) {
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m)
            return false;

        if (grid[i][j] == '(')
            bal++;
        else
            bal--;

        if (bal < 0 || bal > n + m)
            return false;

        if (i == n - 1 && j == m - 1)
            return bal == 0;

        if (memo[i][j][bal] != -1)
            return memo[i][j][bal];

        return memo[i][j][bal] =
            validPath(grid, i + 1, j, bal) ||
            validPath(grid, i, j + 1, bal);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
            return false;

        if ((n + m - 1) % 2 != 0)
            return false;

        memset(memo, -1, sizeof(memo));

        return validPath(grid, 0, 0, 0);
    }
};