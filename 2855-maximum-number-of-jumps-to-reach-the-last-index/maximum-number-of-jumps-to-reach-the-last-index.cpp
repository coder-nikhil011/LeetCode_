class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, 0);

        for(int i=n-2; i>=0; i--){
            int temp = -1e5;
            for(int j=i + 1; j<n; j++){
                if(abs(nums[i] - nums[j]) <= target){
                    temp = max(temp, dp[j] + 1);
                }
            }

            dp[i] = temp;
        }
    
        int ans = dp[0];
        return (ans > 0 ? ans : -1);
    }
};