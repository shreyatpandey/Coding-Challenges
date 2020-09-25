#include <iostream>
#include <bitset>


int main()
{
    int Number[4] = {70,77,80,96};
    std::bitset<8>NetworkInput(Number[1]);
    std::cout<<"----|Print 77 in Binary|----"<<std::endl;
    std::cout<<NetworkInput<<std::endl;
    std::cout<<"----|Perform Necessary Operation|----"<<std::endl;
    int ResultantOperation = (Number[1]&0x7C)<<1;
    std::bitset<8>Result(ResultantOperation);
    std::cout<<Result<<std::endl;
    return 0;
}
//Output
----|Print 77 in Binary|----                                                                                                                                                       
01001101                                                                                                                                                                           
----|Perform Necessary Operation|----                                                                                                                                              
10011000
