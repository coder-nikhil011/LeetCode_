class Solution { 
public: 
    int minEatingSpeed(vector<int>& piles, int h) { 
        int n = piles.size(); 
        
        /*long long k = 1; 

        while (true) { 
            long long total_hours = 0; 
            for(int i = 0; i < n; i++){ 
                total_hours += (piles[i] + k - 1) / k; 
            } 
            
            if(total_hours <= h){ 
                break; 
            } else { 
                k++; // Ek-ek karke speed badhayein
            } 
        } 
        return k; */

        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total_hours = 0;

            for (int pile : piles) {
                total_hours += (pile + mid - 1) / mid;
            }

            if (total_hours <= h) {
                ans = mid; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    } 
};
