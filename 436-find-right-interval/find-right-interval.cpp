class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int, int>> start;
        vector<int> ans(n, -1);

        // Store {start, original index}
        for (int i = 0; i < n; i++) {
            start.push_back({intervals[i][0], i});
        }

        sort(start.begin(), start.end());

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];

            // Find first start >= end
            auto it = lower_bound(start.begin(), start.end(),
                                  make_pair(end, -1));

            if (it != start.end()) {
                ans[i] = it->second;
            }
        }

        return ans;
    }
};