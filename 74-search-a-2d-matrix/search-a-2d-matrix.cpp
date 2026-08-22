class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = (m*n) - 1;

        while(l<=r){
            int mid = l + (r-l)/2;

            int ans = matrix[mid / m][mid % m];

            if(ans == target){
                return true;
            }else if(ans < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};