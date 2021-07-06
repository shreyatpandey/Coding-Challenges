/*
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
*/
//Approach-1
//Will not work for edge case :- [9,9,9,9,9,9,9,9,9,9] k = 1
vector<int>Result;
        int Digit = 0;
        for(int i=0;i<num.size();i++)
        {
            Digit += num[num.size()-i-1]*pow(10,i);
        }
        int Resultant = Digit + k;
        while(Resultant)
        {
            int Remainder = Resultant%10 ;
            Resultant /= 10;
            Result.emplace_back(Remainder);
        }
        reverse(Result.begin(),Result.end());
        return Result;
        
    }

//Approach-2
vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int NumSize = num.size();
        int Current = k;
        int i = NumSize-1;
        vector<int>Result;
        while(Current>0 || i>=0)
        {
            int Sum = Current;
            if(i>=0)
            {
                Sum += num[i];
            }
                Result.emplace_back(Sum%10);
                Current = Sum/10;
            
            i -= 1 ;
        }
        reverse(Result.begin(),Result.end());
        return Result;
    }
