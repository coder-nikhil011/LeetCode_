class Solution { 
public: 
    bool checkDivisibility(int n) { 
        if(n < 10) return false;
        //if(n % 10 == 0) return true;
        int sum = 0; 
        int mul = 1; 
        int temp = n;

        while (temp > 0) { 
            int digit = temp % 10; 
            sum += digit; 
            mul *= digit; 
            temp /= 10; 
        }
        if (n == 0) return false; 

        return n % (sum + mul) == 0; 
    } 
};
