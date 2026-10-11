class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> diff(nums1.size());
        long long sum = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }

        if (sum <= k)
            return 0;

        sort(diff.begin(), diff.end(), greater<long long>());

        diff.push_back(0);
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            long long need = (diff[i] - diff[i + 1]) * (i + 1);

            if (k >= need) {
                k -= need;
            } else {
                long long level = diff[i] - k / (i + 1);
                long long rem = k % (i + 1);
                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    long long val = level;
                    if (j < rem)
                        val--;

                    ans += val * val;
                }

                for (int j = i + 1; j < n; j++)
                    ans += diff[j] * diff[j];

                return ans;
            }
        }

        return 0;
    }
};