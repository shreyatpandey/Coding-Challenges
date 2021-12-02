class Solution {
    private:
        int Result(queue<char>&Queue);
public:
    int calculate(string s) {
        queue<char>Queue;
        for(char c:s)
        {
            if ( c != ' ')
            {
                Queue.push(c);
            }
        }
        /* put placeholder in Queue*/
        Queue.push(' ');
        return Result(Queue);
    }
};
int Solution::Result(queue<char>&Queue)
{
    int prev = 0, num = 0, sum = 0;
    char prevOp = '+';
    while(Queue.size())
    {
        char Temp = Queue.front();
        Queue.pop();
        if (isdigit(Temp))
        {
            num = num*10 + (Temp - '0');
        }
       
        else  
        {
            switch(prevOp)
            {
                case '+':
                    sum += prev;
                    prev = num;
                    break;
                case '-':
                    sum += prev;
                    prev =-num;
                    break;
                case '*':
                    prev *= num;
                    break;
                case '/':
                    prev /= num;
                    break;
                
            }
            prevOp = Temp;
            num = 0;
        }
    }
    return prev + sum;
}
