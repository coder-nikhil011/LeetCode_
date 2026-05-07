class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n);
        vector<int> pre_max(n);
        
        pre_max[0] = nums[0];
        
        for(int i=1; i<n; i++){
            pre_max[i] = max(pre_max[i- 1], nums[i]);
        }
        
        result[n - 1] = pre_max[n - 1];
        int suff_min = nums[n - 1];
        
        for(int i=n-2; i>=0; i--){
            if(pre_max[i] <= suff_min) result[i] = pre_max[i];
            else result[i] = result[i + 1];

            suff_min = min(nums[i], suff_min);
        }
        
        return result;
    }
};