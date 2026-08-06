class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        
        int i = 2;
    
        while (i <= x / i) {
            i++;
        }

        return i - 1;
    }
};
