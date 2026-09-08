class Solution { 
public: 
    int countCommas(int n) { 
        for( ; n <= 100000; ){ 
            if(n >= 1000){ 
                return n - 1000 + 1; 
            }else if(n >= 100000){ 
                return n - 10000 + 1; 
            } 
            break;
        } 
        return 0; 
    } 
};
