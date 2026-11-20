class Solution {
public:
    int n;
    int dp[100001][2];

    int findMethod(vector<int>& nums, int start, int tar){
        int j = lower_bound(begin(nums) + start, end(nums), tar) - begin(nums);

        if(j < n && nums[j] == tar) return j;

        return -1;
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(begin(nums), end(nums));

        memset(dp, -1, sizeof(dp));

        for(int i=n-1; i>=0; i--){
            for(int inc = 0; inc<=1; inc++){
                int curr_val = nums[i] + inc;
                int len = 1;

                // 1st option = find(curr_val + 1)
                int j = findMethod(nums, i + 1, curr_val + 1);
                if(j != -1){
                    len = max(len, 1 + dp[j][0]);
                }

                // 2st option = find(curr_val) and increment 1
                j = findMethod(nums, i + 1, curr_val);
                if(j != -1){
                    len = max(len, 1 + dp[j][1]);
                }

                dp[i][inc] = len;
            }
        }

        int result = 1;
        for(int i=0; i<n; i++){
            result = max({result, dp[i][0], dp[i][1]});
        }

        return result;
    }
};