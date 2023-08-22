#include <stdio.h>
#include<stdint.h>

int main()
{
    uint32_t num = 9;
    uint32_t result = 0;
    result = ((num & 0x000000ff)<<24)|((num&0x0000ff00)<<8)|((num&0x00ff000)>>8)|((num&0xff00000)>>24);
    printf("%u\n",result);

    return 0;
}
