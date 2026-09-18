class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        
        // Step 1: Record the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            leftmost[s[i] - 'a'] = min(leftmost[s[i] - 'a'], i);
            rightmost[s[i] - 'a'] = i;
        }
        
        // Helper lambda to find the valid right boundary for an interval starting at i
        auto getValidRightBoundary = [&](int i) {
            int right = rightmost[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                // If a character inside the window appeared before our start index 'i',
                // then 'i' cannot be the starting point of a valid substring.
                if (leftmost[s[j] - 'a'] < i) {
                    return -1;
                }
                right = max(right, rightmost[s[j] - 'a']);
            }
            return right;
        };
        
        vector<string> ans;
        int lastRight = -1; 
        
        // Step 2 & 3: Iterate and greedily process valid intervals
        for (int i = 0; i < n; ++i) {
            // Only attempt to start a substring at a character's first appearance
            if (i == leftmost[s[i] - 'a']) {
                int newRight = getValidRightBoundary(i);
                if (newRight == -1) continue; 
                
                // If the new substring is completely enclosed within the previous one,
                // replace the previous one since we prefer shorter substrings (greedy choice).
                if (i <= lastRight && !ans.empty()) {
                    ans.back() = s.substr(i, newRight - i + 1);
                } else {
                    // Otherwise, it's non-overlapping, so we append it
                    ans.push_back(s.substr(i, newRight - i + 1));
                }
                lastRight = newRight;
            }
        }
        
        return ans;
    }
};
