/*
File file("abc");
Solution sol;
// Assume buf is allocated and guaranteed to have enough space for storing all characters from the file.
sol.read(buf, 1); // After calling your read method, buf should contain "a". We read a total of 1 character from the file, so return 1.
sol.read(buf, 2); // Now buf should contain "bc". We read a total of 2 characters from the file, so return 2.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
*/
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
     queue<int> left;
    int read(char *buf, int n) {
         int len = 0;
        int c;
        while (left.size() > 0) {
            buf[len++] = left.front();
            left.pop();
            if (len == n) return len;
        }
        
        while (len < n) {
            c = read4(buf+len);
            len += c;
            if (c < 4) break;
        }
        
        for (int i=n; i<len; i++) {
            left.push(buf[i]);
        }
        int e = min(len, n);
        buf[e] = '\0';
        return e;
    }
};
