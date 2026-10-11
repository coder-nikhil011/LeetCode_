

class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 1; i <= n; ++i) {
            // Check if 1-based index 'i' divides 'n'
            if (n % i == 0) {
                // Corresponding 0-based element is nums[i - 1]
                totalSum += nums[i - 1] * nums[i - 1];
            }
        }

        return totalSum;
    }
};