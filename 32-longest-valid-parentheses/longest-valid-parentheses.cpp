class Solution {
public:
    int longestValidParentheses(string s) {
        int n= s.length();
        stack<int>st;
        st.push(-1);
        int length = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }else{
                    length = max(length, i - st.top());
                }
            }

            /*char top = st.top();
            st.pop();

            if(top == '(' && s[i] == ')'){
                count++;
            }*/
        }
        return length;
    }
};