//Pythagoras Theorem
/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
*/
//Approach-1: Without using sqrt function
//TC:- O(sqrt(c)*log(c))
//SC:- O(log(c)) for each recursion for binary search
class Solution {
bool BinarySearchHelper(long Start, long End,int n);
    
public:
    bool judgeSquareSum(int c) {
        for( long a=0;pow(a,2)<= c; a++)
        {
            int b = c - (int)pow(a,2);
            if ( BinarySearchHelper(0,b,b))
                return true;
        }
        return false;
    }
};
bool Solution::BinarySearchHelper(long Start, long End, int n) //recursive
{
    if ( Start > End )
        return false;
    long Mid = Start + (End-Start)/2;
    if ( Mid* Mid == n)
    {
        return true;
    }
    if ( Mid* Mid > n)
    {
      return BinarySearchHelper(Start, Mid-1,n);
    }
    return BinarySearchHelper(Mid+1,End,n);
}
bool Solution::BinarySearchHelper(long Start, long End, int n) //iterative
{
    while ( Start<=End)
    {
        long Mid = Start+(End-Start)/2;
        if ( Mid*Mid == n)
            return true;
        if ( Mid*Mid>n)
            {
                End = Mid-1;
            }
        else
        {
            Start = Mid+1;
        }
    }
    return false;
}


//Approach-2: Using sqrt function
class Solution {
public:
    bool judgeSquareSum(int c) {

        /* using sqrt function */
        for(long a=0;pow(a,2) <=c ; a++)
        {
            double b = sqrt(c-pow(a,2));
            if ( b == (int)b)
                return true;
        }
        return false;
       }
};
        
