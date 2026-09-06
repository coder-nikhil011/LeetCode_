class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int>diff(n,0);

        for(int i = 0; i<n; i++){
            int curr_cap = capacity[i];
            int curr_rocks = rocks[i];

            int required_rock = curr_cap - curr_rocks;
            diff[i] = required_rock;
        }
        sort(begin(diff),end(diff));
        int count = 0;

        for(int i = 0; i<n; i++){
            if(diff[i] == 0){
                count++;
            }else{
                if(diff[i] <= additionalRocks){
                    additionalRocks -= diff[i];
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};