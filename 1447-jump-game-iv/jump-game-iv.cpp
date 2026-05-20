class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();

        unordered_map<int,vector<int>> m;

        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }

        queue<int> q;

        vector<bool> vis(n,false);

        q.push(0);
        vis[0]=true;

        int cnt=0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int idx = q.front();
                q.pop();

                if(idx == n-1) return cnt;

                if(idx < n-1 && !vis[idx + 1]){
                    q.push(idx + 1);
                    vis[idx + 1] = true;
                }

                if(idx > 0 && !vis[idx - 1]){
                    q.push(idx - 1);
                    vis[idx - 1] = true;
                }

                if(m.count(arr[idx])){
                    for(auto i:m[arr[idx]]){
                        if(!vis[i]){
                            q.push(i);
                            vis[i] = true;
                        }
                    }

                    m.erase(arr[idx]); // necessery since the loop can go upto order of n^2
                }
            }

            cnt++;
        }
        
        return 0;
    }
};