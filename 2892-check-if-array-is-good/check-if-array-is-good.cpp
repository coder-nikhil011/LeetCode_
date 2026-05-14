class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // maximum should be n-1
        if(nums[n - 1] != n - 1)
            return false;

        // check 1 to n-2 appear once
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != i + 1)
                return false;
        }

        // last element should also be n-1
        return nums[n - 1] == nums[n - 2];
    }
};