class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open = 0, close = 0, ans = 0;

        /*for(int i : s){
            if(i == '('){
                open++;
            }else{
                close++;
            }
        }
        ans = abs(open - close);
        return ans;
        */
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                open++;
            } else {
                if (!st.empty()) {
                    int front = st.top();
                    st.pop();
                    open--;
                }else{
                    close++;
                }
            }
        }
        ans = open + close;
        return ans;
    }
};