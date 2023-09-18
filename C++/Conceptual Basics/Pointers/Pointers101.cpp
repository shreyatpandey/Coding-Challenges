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
