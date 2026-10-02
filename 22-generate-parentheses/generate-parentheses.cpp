class Solution {
private:
    void backtrack(vector<string>& result, string current, 
                   int openCount, int closeCount, int maxPairs) {
        
        // Base case: string reached max length (2 * n)
        if (current.length() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have open brackets available
        if (openCount < maxPairs) {
            backtrack(result, current + "(", openCount + 1, closeCount, maxPairs);
        }

        // Add ')' if it won't break balance
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, maxPairs);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};