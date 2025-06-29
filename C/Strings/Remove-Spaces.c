#include <stdio.h>
#include <string.h>

void removeSpaces(char *str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Null-terminate the modified string
}

int main() {
    char str[] = "This is a test string";
    printf("Original string: '%s'\n", str);
    removeSpaces(str);
    printf("String without spaces: '%s'\n", str);
    return 0;
}
