class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            stack<char> st;
            bool valid = true;

            for (char c : curr) {
                if (c == '(')
                    st.push(c);
                else if (c == ')') {
                    if (st.empty()) {
                        valid = false;
                        break;
                    }
                    st.pop();
                }
            }

            if (valid && st.empty()) {
                ans.push_back(curr);
                found = true;
            }

            if (found)
                continue;

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.insert(next).second)
                    q.push(next);
            }
        }

        return ans;
    }
};