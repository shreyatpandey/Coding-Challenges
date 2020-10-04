//Approach-1
//Leetcode Solution
class Solution {
    private:
        int HALF_INT_MIN = INT_MIN/2;
public:
    int divide(int dividend, int divisor) {
        if(!(divisor)||dividend == INT_MIN && divisor == -1)
		return INT_MAX;
        int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }

    int quotient = 0;
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    while (divisor >= dividend) {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        int powerOfTwo = -1;
        int value = divisor;
        /* Check if double the current value is too big. If not, continue doubling.
        * If it is too big, stop doubling and continue with the next step */
        while (value >= HALF_INT_MIN && value + value >= dividend) {
            value += value;
            powerOfTwo += powerOfTwo;
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo;
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value;
    }

    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        quotient = -quotient;
    }
    return quotient;
}
       
};

//Approach-2
//CTCI:- Does not work for the case INT_MAX and divisor = 2 or so on
class Solution {
    private:
        int negate(int a);
public:
    int divide(int dividend, int divisor) {
        //handling overflow cases for INT_MAX 
        if ( (dividend == INT_MIN && divisor == -1) || (dividend == INT_MAX && divisor == 1) )
            return INT_MAX;
        //handling overflow cases for INT_MIN
        if ((dividend == INT_MIN && divisor == 1  || (dividend == INT_MAX && divisor == -1)))
            return INT_MIN;
        
        int absa = abs(dividend);
        int absb = abs(divisor);
        
        int product  = 0;
        int x = 0;
        while ( (product + absb <= absa) ) //Integer overflow  
        {
            product += absb ;
            x++;
        }
        if ( (dividend<0 && divisor<0) || (dividend>0 && divisor>0))
        {
            return x;
        }
        else
        {
            return negate(x);
        }
        
    }
};
int Solution::negate(int a)
{
    int neg = 0;
    int newSign = a < 0? 1:-1;
    int delta = newSign ;
    while ( a != 0)
    {
        bool differentSigns = ( a + delta > 0) != (a > 0);
        if ( a + delta !=0 && differentSigns)
        {
            delta = newSign;
        }
        neg += delta ;
        a += delta ;
        delta += delta;
    }
    return neg;
}


	
	
