class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        // 1. Count global frequencies of each number
        for (int i : nums) {
            mp[i]++;
        }

        // Case 1: When k equals the array size
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 2: When k is 1, find the largest unique element
        if (k == 1) {
            int max_val = -1;
            for (const auto& [element, count] : mp) {
                if (count == 1) {
                    max_val = max(max_val, element);
                }
            }
            return max_val;
        }

        // Case 3: When 1 < k < n, only the edges can appear in exactly 1
        // subarray
        if (k > 1 && k < n) {
            // Case 1: Both elements occur exactly once -> return the maximum of
            // the two
            if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) {
                return max(nums[0], nums[n - 1]);
            }

            // Case 2a: Only nums[0] occurs once (nums[n-1] occurs more than
            // once) -> return nums[0]
            else if (mp[nums[0]] == 1 && mp[nums[n - 1]] > 1) {
                return nums[0];
            }

            // Case 2b: Only nums[n-1] occurs once (nums[0] occurs more than
            // once) -> return nums[n-1]
            else if (mp[nums[0]] > 1 && mp[nums[n - 1]] == 1) {
                return nums[n - 1];
            }

            // Case 3: Both elements occur more than once -> return -1
            else if (mp[nums[0]] > 1 && mp[nums[n - 1]] > 1) {
                return -1;
            }
        }
        return -1;
    }
};
