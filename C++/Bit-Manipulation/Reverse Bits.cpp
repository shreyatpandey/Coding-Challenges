/*
Reverse bits of a given 32 bits unsigned integer
*/
/* Without Using For-Loop*/
//Appraoch-1
//Faster than 60.11% of C++
class Solution
{
 public:
  uint32_t reverseBits(uint32_t n)
  {
	n = ((n&0xaaaaaaaa)>>1|(n&0x55555555)<<1); // swap one bits at a time
        n = ((n&0xcccccccc)>>2|(n&0x33333333)<<2); //swap two bits at a time
        n = ((n&0xf0f0f0f0)>>4|(n&0x0f0f0f0f)<<4); //swap four bits at a time
        n = ((n&0xff00ff00)>>8|(n&0x00ff00ff)<<8);
        n = (n>>16|n<<16);
        return n;	  
	  
  }
};

/* Using For-Loop */
//Approach - 2
//faster than 60.11% of Solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       int CountBits = 31;
        uint32_t temp = 0;
       for(int Loop = 0;Loop<=CountBits;Loop++)
       {
           if(n&(1<<Loop))
           {
               int maskvalue = (1<<(CountBits-Loop));
               temp |= maskvalue;
           }
       }
        
        return temp;
    }
};

