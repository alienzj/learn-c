#include <zlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


unsigned long file_size(char *file_name)
{
    FILE *file = fopen(file_name, "rb");
    fseek(file, 0, SEEK_END);
    unsigned long size = ftell(file);
    fclose(file);
    return size;
}


int main(int argc, char *argv[])
{
    const char *file_name = argv[1];
    printf("%s\n", file_name);
    gzFile file_in = gzopen(file_name, "rb");

    if (!file_in) {
        fprintf(stderr, "gzopen of '%s' failed: %s.\n", file_name,
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    while(1) {
        int err;
        int bytes_read;
        unsigned char buffer[1000];
        bytes_read = gzread(file_in, buffer, 999);
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        if (bytes_read < 999) {
            if (gzeof(file_in)) {
                break;
            }
            else {
                const char* error_string;
                error_string = gzerror(file_in, &err);
                if (err) {
                    fprintf(stderr, "Error: %s.\n", error_string);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    gzclose(file_in);
    return 0;
}
