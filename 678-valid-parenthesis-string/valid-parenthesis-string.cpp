class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int cmin = 0; 
        int cmax = 0; 

        for (char i : s) {
            if (i == '(') {
                cmax++;
                cmin++;
            } else if (i == '*') {
                cmax++;   // If * acts as '('
                cmin--;   // If * acts as ')'
            } else {      // i == ')'
                cmax--;
                cmin--;
            }
            
            if (cmax < 0) return false; 
            if (cmin < 0) cmin = 0;     
        }

        return cmin == 0; 
    }
};
