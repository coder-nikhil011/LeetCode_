class Solution { 
public: 
    string shortestBeautifulSubstring(string s, int k) { 
        int n = s.length(); 
        string ans = ""; 
        int i = 0; 
        int j = 0;
        int count = 0; 
        int len = INT_MAX; 

        while(j < n){ 
            if(s[j] == '1'){ 
                count++; 
            } 
            while(count == k){ 
                if(j - i + 1 < len){ 
                    len = j - i + 1; 
                    ans = s.substr(i, len);
                } else if(j - i + 1 == len){
                    string temp = s.substr(i, len);
                    if(temp < ans){
                        ans = temp;
                    }
                }
                if(s[i] == '1'){
                    count--;
                }
                i++; 
            }
            j++; 
        } 
        return ans; 
    } 
};
