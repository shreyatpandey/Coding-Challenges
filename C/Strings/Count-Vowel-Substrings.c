#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// LeetCode 2062. Count Vowel Substrings of a String
// A substring is a contiguous (non-empty) sequence of characters within a string.
// A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', 'u') and has all five vowels present in it.
// Given a string word, return the number of vowel substrings in word.

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/**
 * @brief Counts the number of vowel substrings in a word.
 * 
 * This is a brute-force O(n^2) approach.
 * It iterates through all possible substrings, and for each substring,
 * it checks if it's a valid vowel substring.
 * A substring is valid if it contains only vowels and has all 5 vowels.
 * 
 * @param word The input string.
 * @return The number of vowel substrings.
 */
int countVowelSubstrings(char * word) {
    int count = 0;
    int n = strlen(word);
    if (n < 5) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int vowels[5] = {0}; // a, e, i, o, u
        int distinct_vowels = 0;
        for (int j = i; j < n; j++) {
            char c = word[j];
            if (!is_vowel(c)) {
                break; // End of vowel-only substring
            }

            int vowel_index = -1;
            if (c == 'a') vowel_index = 0;
            else if (c == 'e') vowel_index = 1;
            else if (c == 'i') vowel_index = 2;
            else if (c == 'o') vowel_index = 3;
            else if (c == 'u') vowel_index = 4;

            if (vowels[vowel_index] == 0) {
                distinct_vowels++;
            }
            vowels[vowel_index]++;

            if (distinct_vowels == 5) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char word1[] = "aeiouu";
    printf("'%s': %d\n", word1, countVowelSubstrings(word1));

    char word2[] = "unicornarihan";
    printf("'%s': %d\n", word2, countVowelSubstrings(word2));

    char word3[] = "cuaieuouac";
    printf("'%s': %d\n", word3, countVowelSubstrings(word3));

    char word4[] = "bbaeixoubb";
    printf("'%s': %d\n", word4, countVowelSubstrings(word4));
    
    return 0;
}
