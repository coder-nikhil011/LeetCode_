class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int remove = nums.size() - k;
        vector<int> st;

        for (int num : nums) {
            while (!st.empty() && remove > 0 && st.back() < num) {
                st.pop_back();
                remove--;
            }
            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    bool greaterVec(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size()) {
            if (a[i] > b[j]) return true;
            if (a[i] < b[j]) return false;
            i++;
            j++;
        }
        return i != a.size();
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greaterVec(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int take1 = start; take1 <= end; take1++) {
            int take2 = k - take1;

            vector<int> a = maxSubsequence(nums1, take1);
            vector<int> b = maxSubsequence(nums2, take2);

            vector<int> cur = merge(a, b);

            if (greaterVec(cur, 0, ans, 0))
                ans = cur;
        }

        return ans;
    }
};