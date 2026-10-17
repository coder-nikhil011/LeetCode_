class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        vector<pair<pair<int, int>, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i)
                continue;

            int j = i;
            int cnt = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};