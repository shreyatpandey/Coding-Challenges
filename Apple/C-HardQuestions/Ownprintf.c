#include<stdio.h> 
#include<stdarg.h>
#include<stdlib.h>
 
void Myprintf(char *,...); 				
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.
 
void Myprintf(char* format,...) 
{ 
	char *traverse; 
	unsigned int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	
	for(traverse = format; *traverse != '\0'; traverse++) 
	{ 
		while( *traverse != '%' ) 
		{ 
			traverse++; 
		} 
		
		traverse++; 
		
		//Module 2: Fetching and executing arguments
		switch(*traverse) 
		{ 
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						putchar(i);
						break; 
						
			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						if(i<0) 
						{ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break; 
						
			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
						puts(convert(i,8));
						break; 
						
			case 's': s = va_arg(arg,char *); 		//Fetch string
						puts(s); 
						break; 
						
			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						puts(convert(i,16));
						break; 
		}	
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 
 
char *convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	char *ptr = (char*)malloc(sizeof(char*));
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	return(ptr); 
}

int main() 
{ 
	printf("|---Test-Case: 1 ---|\n");
	Myprintf(" Integer-Value: %d", 9);
	printf("\n");
	
	printf("|---Test-Case 2 ---|\n");
	Myprintf("Integer-Value: %d", 56);
	printf("\n");
	
	printf("|---Test-Case 3 ---|\n");
	Myprintf("Hexadecimal Value:%x", 0xab);
	printf("\n");
	
	return 0;
} 
