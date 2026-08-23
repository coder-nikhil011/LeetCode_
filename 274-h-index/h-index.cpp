class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>arr(n+1,0);
        int count = 0;
        for(int i : citations){
            if(i > n){
                arr[n]++;
            }else{
                arr[i]++;
            }
        }

        for(int i = n; i>=0; i--){
            count += arr[i];
            if(i <= count){
                return i;
            }
        }
        return 0;
    }
};