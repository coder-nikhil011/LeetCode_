class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        if(s[n-1] != '0') return false;

        vector<bool> dp(n, false);

        dp[0] = true;
        int cnt = 0;

        for(int i=1; i<n; i++){
            int min_idx = i - maxJump;
            int max_idx = i - minJump;

            cnt += (max_idx >= 0 ? dp[max_idx] : 0) - (min_idx > 0 ? dp[min_idx - 1] : 0);

            if(s[i] == '0'){
                if(cnt > 0) dp[i] = true;
            }
        }

        return dp[n-1];
    }
};