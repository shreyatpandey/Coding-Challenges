#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

/* Following macro can convert Little Endian to Big Endian*/
#define Swap2Bytes(x) ((((x)>>8)&0x00ff)|((((x)<<8)&0xff00)))
#define Swap4Bytes(x) ((((x)>>24)&0x000000FF)) | ((((x)>>8)&0x0000FF00))|\
                        (((x)<<8)&0x00FF0000) | (((x)<<24)&0xFF000000))
                        
#define Max(x,y) (x>y?x:y)

int main()
{
    cout<<"Swap2Bytes:"<<Swap2Bytes(11)<<endl;
    printf("%x\n", Swap2Bytes(11));

    return 0;
}
