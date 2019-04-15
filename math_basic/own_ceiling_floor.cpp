#include <stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

class Solution
{
    public:
        int own_floor(float input_1,float input_2)
        {
            double div_value = input_1/input_2 ;
            return (div_value - fmod(div_value,1));
        }
        int own_ceiling(int input_1,int input_2)
        {
            return (input_1/input_2 + ((input_1%input_2) != 0));
        }
};
int main()
{
    Solution *s = new Solution;
    cout<<"floor_value:"<<s->own_floor(7,3)<<endl;
    cout<<"ceiling_value:"<<s->own_ceiling(7,3)<<endl;
    return 0;
}
