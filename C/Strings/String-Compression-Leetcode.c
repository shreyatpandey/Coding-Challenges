/**
 * String Compression - LeetCode Problem
 * 
 * Given an array of characters chars, compress it using the following algorithm:
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * - If the group's length is 1, append the character to s.
 * - Otherwise, append the character followed by the group's length.
 * 
 * The compression must be done in-place.
 */

int compress(char* chars, int charsSize) {
    if (charsSize == 0) return 0;
    
    int write = 0;  // Position where we'll write the compressed result
    int anchor = 0; // Start of the current group
    
    for (int read = 0; read < charsSize; read++) {
        // If we're at the end or next character is different
        if (read + 1 == charsSize || chars[read] != chars[read + 1]) {
            // Write the current character
            chars[write++] = chars[anchor];
            
            int groupLength = read - anchor + 1;
            if (groupLength > 1) {
                // Convert the number to string and write it
                // First, calculate how many digits we need
                int count = groupLength;
                char digits[10];  // Max number of digits for an int
                int numDigits = 0;
                
                while (count > 0) {
                    digits[numDigits++] = (count % 10) + '0';
                    count /= 10;
                }
                
                // Write digits in reverse (to get correct order)
                for (int i = numDigits - 1; i >= 0; i--) {
                    chars[write++] = digits[i];
                }
            }
            
            anchor = read + 1;
        }
    }

    return write;
}
/* Issue with digit writing loop 
    * Without the loop to write digits in correct order,
    * numbers like "12" would be written as "21"
    * or worse, not written at all!
*/