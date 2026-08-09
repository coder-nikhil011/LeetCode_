class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;

        int lo = 1;
        int high = num / 2;

        while (lo <= high) {
            long long mid = lo + (high - lo) / 2;

            if (mid * mid == num)
                return true;

            else if (mid * mid < num)
                lo = mid + 1;

            else
                high = mid - 1;
        }
        /*for(long long i = 0; i<=num;i++){
            if(i * i == num){
                return true;
            }
        }*/
        return false;
    }
};