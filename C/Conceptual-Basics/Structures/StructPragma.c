#include <stdio.h> 
  
struct s { 
    int i; 
    char ch; 
    double d; 
}; 

#pragma pack(1)
struct packing_pragma
{
	int i;
	char ch;
	double d;
};

struct packing_attribute { 
    int i; 
    char ch; 
    double d; 
} __attribute__((packed));

  
int main() 
{ 
    struct s A; 
    struct packing_pragma pragma_case;
    struct packing_attribute attribute;
    
    printf("Size of A is: %ld\n", sizeof(A)); // round it off the next highest power of 2
    printf("Size of packing_pragma is:%ld\n",sizeof(pragma_case));
    printf("Size of packing_attribute is:%ld\n",sizeof(attribute)); 
    printf("Size of int:%ld\n",sizeof(int));
    printf("Size of double:%ld\n",sizeof(double));
    printf("Size of char:%d\n",sizeof(char));
    printf("Hence size of struct is sum of all datatypes inside struct\n");
} 
/*
Size of A is: 16
Size of packing_pragma is:13
Size of packing_attribute is:13
Size of int:4
Size of double:8
Size of char:1
Hence size of struct is sum of all datatypes inside struct
*/
