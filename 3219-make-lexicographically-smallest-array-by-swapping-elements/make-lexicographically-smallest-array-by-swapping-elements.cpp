class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<pair<int, int>> paired(n);
        for (int i = 0; i < n; ++i) {
            paired[i] = {nums[i], i};
        }
        
        sort(paired.begin(), paired.end());
        
        vector<int> result(n);
        int i = 0;
        
        while (i < n) {
            int j = i;
            vector<int> indices;
            
            while (j < n && (j == i || paired[j].first - paired[j - 1].first <= limit)) {
                indices.push_back(paired[j].second);
                j++;
            }
            
            sort(indices.begin(), indices.end());
            
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = paired[i + k].first;
            }
            
            i = j;
        }
        
        return result;
    }
};