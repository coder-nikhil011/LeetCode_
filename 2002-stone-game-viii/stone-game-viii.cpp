class Solution {
public:
    // int n;
    // int t[100001];
    // c

    /*int solve(int i) {
        if (i == n - 1) {
            return prefixSum[n - 1];
        }
        if (t[i] != -1) return t[i];

        int take = prefixSum[i] - solve(i + 1);
        int skip = solve(i + 1);

        return t[i] = max(take, skip);
    }*/

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        // memset(t, -1, sizeof(t));
        vector<int> prefixSum;

        // prefixSum.resize(n, 0);
        prefixSum = stones;
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        vector<int> t(n);

        t[n - 1] = prefixSum[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i + 1];

            t[i] = max(take, skip);
        }

        return t[1];
    }
};
