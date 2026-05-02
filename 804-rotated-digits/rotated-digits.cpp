class Solution {
public:
    int rotatedDigits(int n) {
        int res;
        for(int i = 1; i<=n;i++){
            string num = to_string(i);
            bool valid = false;
            bool invalid = false;
            for(char c : num){
                if(c == '2' ||c == '5'|| c == '6'||c == '9'){
                    valid = true;
                }
                if(c == '3'||c == '4'||c == '7'){
                invalid = true;
                break;
                }
            }

            if(valid && !invalid){
                res++;
            }
        }
        return res;
    }
};