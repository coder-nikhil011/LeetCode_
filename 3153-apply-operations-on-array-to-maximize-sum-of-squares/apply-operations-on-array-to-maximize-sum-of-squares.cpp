class Solution {
public:
    static const int MOD = 1e9 + 7;
    
    int maxSum(vector<int>& nums, int k) {
        // 1. Count frequencies of each bit
        const int MAXB = 31;
        int cnt[MAXB] = {};
        for (int x : nums) {
            for (int b = 0; b < MAXB; ++b) {
                if (x & (1 << b)) {
                    cnt[b]++;
                }
            }
        }

        // 2. Build k largest possible numbers greedily
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long cur = 0;
            for (int b = 0; b < MAXB; ++b) {
                if (cnt[b] > 0) {
                    cur |= (1LL << b); // set the b-th bit
                    cnt[b]--;          // consume one instance of this bit
                }
            }
            // 3. Add square to answer
            cur %= MOD;
            ans = (ans + cur * cur) % MOD;
        }

        return ans;
    }
};