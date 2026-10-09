class Solution:
    def minInsertions(self, s: str) -> int:
        ans = 0
        open_count = 0
        i = 0
        n = len(s)
        
        while i < n:
            if s[i] == '(':
                open_count += 1
                i += 1
            else:
                # s[i] is ')'
                # Check if next char is also ')'
                if i + 1 < n and s[i + 1] == ')':
                    i += 2
                else:
                    ans += 1  # Insert one ')' to make a pair
                    i += 1
                
                # Now we have a complete pair of "))"
                if open_count > 0:
                    open_count -= 1
                else:
                    ans += 1  # Insert one '(' to match this pair
        
        # Each remaining '(' needs two ')'
        ans += open_count * 2
        return ans