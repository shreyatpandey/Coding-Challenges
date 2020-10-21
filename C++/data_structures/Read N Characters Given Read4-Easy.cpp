/*
The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf4.

The return value is the number of actual characters read.

Note that read4() has its own file pointer, much like FILE *fp in C.

Definition of read4:

    Parameter:  char[] buf4
    Returns:    int

Note: buf4[] is destination not source, the results from read4 will be copied to buf4[]
*/
/*
Input:- Input: file = "abcde", n = 5
Output: 5
Explanation: After calling your read method, buf should contain "abcde". We read a total of 5 characters from the file, so return 5.
*/
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    private:
        char TempBuffer[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int TotalBytesRead = 0;
        int ActualBytesRead = 4;
        while(TotalBytesRead<n && ActualBytesRead == 4)
        {
            ActualBytesRead = read4(TempBuffer);  
            for(int i=0;i<ActualBytesRead;i++)
            {
                if ( TotalBytesRead == n )
                    return TotalBytesRead;
                buf[TotalBytesRead++] = TempBuffer[i];
            }   
        }
        return TotalBytesRead ;
    }
};
