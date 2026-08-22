class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = cols-1;

        while(l < row && r >= 0){

            int ans = matrix[l][r];

            if(ans == target){
                return true;
            }else if(ans < target){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};