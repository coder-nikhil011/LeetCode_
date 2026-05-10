class Solution {
public:
    int n, m;
    void rotate(vector<vector<int>>& grid, int i, int j, int rows, int cols, int k){
        vector<int> nums;

        //right
        for(int offset = 0; offset + 1 < cols; offset++){
            nums.push_back(grid[i][j + offset]);
        }
        j = j + cols - 1;

        //down
        for(int offset = 0; offset + 1 < rows; offset++){
            nums.push_back(grid[i + offset][j]);
        }
        i = i + rows - 1;

        //left
        for(int offset = 0; offset + 1 < cols; offset++){
            nums.push_back(grid[i][j - offset]);
        }
        j = j - cols + 1;

        //up
        for(int offset = 0; offset + 1 < rows; offset++){
            nums.push_back(grid[i - offset][j]);
        }
        i = i - rows + 1;

        int sz = nums.size();

        k %= sz;

        int curr = k;

        //right
        for(int offset = 0; offset + 1 < cols; offset++){
            grid[i][j + offset] = nums[curr];
            curr = (curr + 1) % sz;
        }
        j = j + cols - 1;

        //down
        for(int offset = 0; offset + 1 < rows; offset++){
            grid[i + offset][j] = nums[curr];
            curr = (curr + 1) % sz;
        }
        i = i + rows - 1;

        //left
        for(int offset = 0; offset + 1 < cols; offset++){
            grid[i][j - offset] = nums[curr];
            curr = (curr + 1) % sz;
        }
        j = j - cols + 1;

        //up
        for(int offset = 0; offset + 1 < rows; offset++){
            grid[i - offset][j] = nums[curr];
            curr = (curr + 1) % sz;
        }
        i = i - rows + 1;
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        int i = 0, j = 0;
        int rows = n, cols = m;
        while(rows && cols){
            rotate(grid, i, j, rows, cols, k);

            i++; j++;
            rows -= 2; cols -= 2;
        }

        return grid;
    }
};