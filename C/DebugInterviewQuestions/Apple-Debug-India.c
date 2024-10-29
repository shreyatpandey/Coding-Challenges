/*
Write a function A to declare a pointer this can also be called in main
Write a function B to assign a pointer
Write a function C to give value to a pointer
Write a function D to print a pointer
Write a function E to free the pointer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void function_B(char **p) {
    printf("B:\n");
    *p = (char*)malloc(sizeof(char));
    assert(*p != NULL);
}
void function_C(char **p) {
    printf("C:\n");
    strncpy(*p, "Hello", strlen("Hello"));
}

void function_D(char *p) {
    printf("%s\n", p);
}

void function_E(char **p) {
    free(*p);
}
int main() {
    char *p = NULL;
    function_B(&p);
    function_C(&p);
    function_D(p);
    function_E(&p);
    p = NULL;
    return 0;
}