#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

// Function to print the last n lines of a file
void tail(FILE* in, int n)
{

    int count = 0;  // To count '\n' characters


    // unsigned long long pos (stores upto 2^64 – 1

    // chars) assuming that long long int takes 8 

    // bytes

    unsigned long long pos;

    char str[2*SIZE];


    // Go to End of file

    if (fseek(in, 0, SEEK_END))

        perror("fseek() failed");

    else

    {

        // pos will contain no. of chars in

        // input file.

        pos = ftell(in);


        // search for '\n' characters

        while (pos)

        {

            // Move 'pos' away from end of file.

            if (!fseek(in, --pos, SEEK_SET))

            {

                if (fgetc(in) == '\n')

                    // stop reading when n newlines

                    // is found

                    if (count++ == n)

                        break;

            }
            else

                perror("fseek() failed");

        }
        // print last n lines

        printf("Printing last %d lines -\n", n);

        while (fgets(str, sizeof(str), in))

            printf("%s", str);

    }

    printf("\n\n");
}