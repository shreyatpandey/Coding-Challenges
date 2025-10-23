#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compressString(char* word) {
    if (word == NULL || strlen(word) == 0) {
        return "";
    }
    
    // Maximum possible length of compressed string
    // For each character we might need 2 chars (1 for count, 1 for char)
    char* comp = (char*)malloc(strlen(word) * 2 + 1);
    int compIndex = 0;
    int wordLen = strlen(word);
    int i = 0;
    
    while (i < wordLen) {
        char currentChar = word[i];
        int count = 0;
        
        // Count consecutive occurrences of currentChar
        // Maximum count allowed is 9
        while (i < wordLen && word[i] == currentChar && count < 9) {
            count++;
            i++;
        }
        
        // Add count and character to compressed string
        comp[compIndex++] = count + '0';  // Convert count to character
        comp[compIndex++] = currentChar;
    }
    
    comp[compIndex] = '\0';  // Null terminate the string
    return comp;
}

int main() {
    // Test cases
    char word1[] = "abcde";
    char word2[] = "aaaaaaaaaaaaaabb";
    
    char* result1 = compressString(word1);
    char* result2 = compressString(word2);
    
    printf("Test Case 1:\n");
    printf("Input: \"%s\"\n", word1);
    printf("Output: \"%s\"\n\n", result1);
    
    printf("Test Case 2:\n");
    printf("Input: \"%s\"\n", word2);
    printf("Output: \"%s\"\n", result2);
    
    // Free allocated memory
    free(result1);
    free(result2);
    
    return 0;
}