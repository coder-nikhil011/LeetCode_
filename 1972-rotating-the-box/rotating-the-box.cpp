class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));

        for(int i = 0;i<n;i++){
            int level = m-1;
            for(int j = m-1;j>=0;j--){
                if(boxGrid[i][j] == '*'){
                    ans[j][n-1-i] = '*';
                    level = j -1;
                }else if(boxGrid[i][j] == '#'){
                    ans[level][n-1-i] = '#';
                    level--;
                }
            }
        }
        return ans;
    }
};