/*
Given an array A of non-negative integers, 
return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int EvenMonitor = 0;
        int OddMonitor = A.size() -1 ;
        while(EvenMonitor < OddMonitor)
        {
            int result1 = A[EvenMonitor] & 1;
            int result2 = A[OddMonitor] & 1;
            if ( result1 != 0  &&  result2 == 0)
                swap(A[EvenMonitor],A[OddMonitor]);
            if ( result1 == 0)
                EvenMonitor++;
            if ( result2 != 0)
                OddMonitor--;
           
        }
        return A;
        
    }
};
