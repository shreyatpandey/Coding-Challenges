#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

typedef struct Point {
    int x, y;
} Point;

int main() {
    Point p1 = {
        .x = 13,
        .y = 10
    };
    Point p2;
    
    FILE *in;
    FILE *out;

    // WRITE 
    out = fopen( "Point.bin", "wb");
    if (out == NULL) {
        return -EINVAL;
    }


    size_t bytes_written = fwrite(&p1, sizeof(Point), 1, out);
    fclose(out);
    if (bytes_written == 0) {
        return -1;
    }

    // READ
    in = fopen("Point.bin", "rb");
    if (in == NULL) {
        return -2;
    }

    size_t element_read = fread(&p2, sizeof(Point),1, in);
    fclose(in);
    if (element_read == 0) {
        return -3;
    }

    printf("Point read from binary file : %d, %d \n", p2.x, p2.y);

    return 0;

}