#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

#define LENS 1000000

int count_from_stdin()
{
    int c;
    long nc = 0;
    while ((c = getchar()) != EOF)
    {
        // EOF: end of file
        putchar(c);
        ++nc;
    }
    printf("\n%ld\n", nc);
    return 0;
}

unsigned long file_size(char *file_name)
{
    FILE *file = fopen(file_name, "rb");
    fseek(file, 0, SEEK_END);
    unsigned long size = ftell(file);
    fclose(file);
    return size;
}

size_t fq(const char *fname)
{
    fprintf(stderr, "\t-> using fgets\n");
    FILE *fp = fopen(fname, "r");
    size_t n_lines = 0;
    char buffer[LENS];
    while (NULL != fgets(buffer, LENS, fp))
        n_lines++;
    fprintf(stderr, "%lu\n", n_lines);
    return n_lines;
}

size_t iz(const char *fname)
{
    fprintf(stderr, "\t-> using zlib\n");
    gzFile fp = gzopen(fname, "r");
    size_t n_lines = 0;
    char buffer[LENS];
    while (0 != gzgets(fp, buffer, LENS))
        n_lines++;
    return n_lines;
}

int print_gzfile(const char *file_name)
{
    gzFile file_in = gzopen(file_name, "rb");
    if (!file_in)
    {
        fprintf(stderr, "gzopen of '%s' failed: %s.\n", file_name,
                strerror(errno));
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        int err;
        int bytes_read;
        unsigned char buffer[1000];
        bytes_read = gzread(file_in, buffer, 999);
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        if (bytes_read < 999)
        {
            if (gzeof(file_in))
            {
                break;
            }
            else
            {
                const char *error_string;
                error_string = gzerror(file_in, &err);
                if (err)
                {
                    fprintf(stderr, "Error: %s.\n", error_string);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    gzclose(file_in);
    return 0;
}
