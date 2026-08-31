class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> next_greater;
        
        // Build the next greater mapping for all elements in nums2
        for (int num : nums2) {
            while (!stk.empty() && stk.top() < num) {
                next_greater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        
        // Build the result for nums1 using our map
        vector<int> ans;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1); // No greater element found
            }
        }
        
        return ans;
    }
};
