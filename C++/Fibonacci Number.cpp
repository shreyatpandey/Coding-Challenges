/*Iterative Solution */
class Solution {
public:
    int fib(int N) {
        if (N <=1)
            return N;
        if(N == 2)
            return 1;
        int firstnumber = 0;
        int secondnumber = 1;
        int temp;
        for(int i=1;i<N;i++)
        {
            temp = firstnumber + secondnumber;
            firstnumber = secondnumber;
            secondnumber = temp;
        }
        return temp;
    }
};

/*Recursive Solution*/
class Solution {
public:
    int fib(int N) {
        if(N<=1)
            return N;
        return fib(N-1) + fib(N-2);
    }
};
