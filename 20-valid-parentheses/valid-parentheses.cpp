class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        for(int i : s){
            if(i == '(' || i == '{' || i == '['){
                st.push(i);
            }else{
                if(st.empty()){
                    return false;
                }
                char front = st.top();
                st.pop();
                if((i == ')' && front != '(') || 
                   (i == '}' && front != '{') || 
                   (i == ']' && front != '[')){ 
                    return false; 
                } 
            }
        }
        return st.empty();
    }
};