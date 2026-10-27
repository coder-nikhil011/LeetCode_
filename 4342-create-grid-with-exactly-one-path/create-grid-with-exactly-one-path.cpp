class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // 1. Fill with obstacles
        vector<string> grid(m, string(n, '#'));
        // 2. Clear the first row
        for (int j = 0; j < n; ++j) grid[0][j] = '.';
        // 3. Clear the last column
        for (int i = 0; i < m; ++i) grid[i][n - 1] = '.';
        return grid;
    }
};