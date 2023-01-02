public class Solution {
    public double MyPow(double x, int n) {
        double answer = 1.0;
        long Value = n; // This is done precisely to handle the Overflow Exception. Exact Error:- 
                        //Unhandled exception. System.OverflowException: Negating the minimum value of a twos complement number is invalid.

        long m = Math.Abs(Value);
        while(m != 0)
        {
            int Result = (int)m&1;
            if(Convert.ToBoolean(Result))
            {
                answer *= x;
            }
            x *= x;
            m >>= 1;
        }

        if(n<0)
        {
            answer = 1/answer;
        }
        return answer;
    }
}
