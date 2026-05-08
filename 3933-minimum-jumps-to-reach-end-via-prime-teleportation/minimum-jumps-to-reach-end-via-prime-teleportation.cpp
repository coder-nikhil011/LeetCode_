class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            int num = nums[i];
            
            for(int div = 2; div*div <= num; div++){
                if(num % div == 0){
                    mp[div].push_back(i);

                    while(num % div == 0) num /= div;
                }
            }

            if(num > 1) mp[num].push_back(i);
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
            if(mp.count(nums[i])){
                for(auto& next_idx:mp[nums[i]]){
                    if(!vis[next_idx]){
                        q.push({next_idx, curr.second + 1});
                        vis[next_idx] = true;
                    }
                }
                mp.erase(nums[i]);
            }
        }

        return 0;
    }
};