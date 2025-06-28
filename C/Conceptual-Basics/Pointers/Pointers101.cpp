// This program gives pointer initialization
#include <iostream>
int main() 
{
    int* A = 1; //Through error as int to int* conversion is not permissive
    int value = 5;
    int *Temp = &value;
    int *Temp1 = new int(10);
    std::cout<<*Temp<<std::endl;
    std::cout<<*Temp1<<std::endl;
    return 0;
}

/*
int *p = 0;
It's a special case. 
This translates into null pointer constant.
Program will compile and won't give any output.
This one line :- int *p = 0 is equivalent to two lines
int *p;
p = 0x0

*/
