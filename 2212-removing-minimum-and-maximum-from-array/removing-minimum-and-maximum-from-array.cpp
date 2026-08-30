class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int leftIdx = min_element(nums.begin(),nums.end()) - nums.begin();
        int rightIdx = max_element(nums.begin(),nums.end()) - nums.begin();

        int left = min(leftIdx,rightIdx);
        int right = max(leftIdx,rightIdx);

        return min({left + 1 + n-right,right+1,n-left});
    }
};