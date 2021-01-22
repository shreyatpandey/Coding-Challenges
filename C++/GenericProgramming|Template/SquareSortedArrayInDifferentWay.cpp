#include<bits/stdc++.h>
using namespace std;
using Array = std::vector<int> ;
void Print(int value)
{
    cout<<value<<" ";
}

int main()
{
    Array Input = {-4,-3,-2,0,1,4,9};
    auto Temp = Input.size() -1 ;
    auto StartIndex = 0;
    auto EndIndex = Input.size() -1;
    Array SquareSortedArray(Input.size(),0);
    while(StartIndex <= EndIndex)
    {
        if ( Input[StartIndex]*Input[StartIndex] <= Input[EndIndex]*Input[EndIndex] )
        {
            SquareSortedArray[Temp--] = Input[EndIndex]*Input[EndIndex];
            EndIndex -= 1;
        }
        else
        {
          SquareSortedArray[Temp--] = Input[StartIndex]*Input[StartIndex] ;
          StartIndex += 1 ;
        }
    }
    for_each(SquareSortedArray.begin(),SquareSortedArray.end(), Print ) ; 
    cout<<endl;
    return 0;
    
}
