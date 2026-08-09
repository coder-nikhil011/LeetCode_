
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int lo = 0;
        int high = n - 1;

        while (lo <= high) {
            int mid = lo + (high - lo) / 2;

            if (letters[mid] > target) {
                high = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }

        // If lo == n, wrap around to the first character
        return letters[lo % n];
    }
};
