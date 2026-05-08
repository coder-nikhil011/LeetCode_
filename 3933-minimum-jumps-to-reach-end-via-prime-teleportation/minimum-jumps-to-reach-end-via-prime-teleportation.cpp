class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(begin(nums), end(nums));

        vector<bool> isPrime(maxi + 1, true);

        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= maxi; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<bool> vis(n, false);

        q.push({0, 0});
        vis[0] = true;

        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            int i = curr.first;

            if(i == n - 1) return curr.second;

            if(i != 0 && !vis[i-1]) {
                q.push({i-1, curr.second + 1});
                vis[i-1] = true;
            }
            if(i != n - 1 && !vis[i+1]) {
                q.push({i+1, curr.second + 1});
                vis[i+1] = true;
            }
            if(isPrime[nums[i]]){
                for(int num = nums[i]; num <= maxi; num += nums[i]){
                    if(mp.count(num)){
                        for(auto& next_idx:mp[num]){
                            if(!vis[next_idx]){
                                q.push({next_idx, curr.second + 1});
                                vis[next_idx] = true;
                            }
                        }
                        mp.erase(num);
                    }
                }
            }
        }

        return 0;
    }
};