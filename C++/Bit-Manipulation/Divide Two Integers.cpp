//TC:- O(N) , N = 32
//SC:- O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend<0)^(divisor<0)?-1:1;
        long long dvd = dividend;
        long long dvs = divisor;
        
        if (dvd == INT32_MIN && dvs == -1) {
            return INT32_MAX;
        }
        
        dvd = abs(dvd);
        dvs = abs(dvs);
        
        long long res = 0;
        
        for (int i = 31; i >= 0; --i) {
          if (dvd >= (dvs << i)) {
            dvd -= (dvs << i);
            res += (1 << i);
          }
        }

        return sign * res;
    
    }
};
	
	
