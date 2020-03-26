#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ex1
    FILE * fp = fopen("io.c", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int c;
    while((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached sucessfully");
    fclose(fp);

    // ex2
    FILE* tmpf = tmpfile();
    fputs("Hello, World!\n", tmpf);
    fputs("Welcome to the bioinformatics community\n", tmpf);
    fputs("Alan Turing\n", tmpf);
    fputs("John von Neumann\n", tmpf);
    fputs("Alonzo Chruch\n", tmpf);

    rewind(tmpf);

    char buf[8];
    while (fgets(buf, sizeof buf, tmpf) != NULL)
        printf("\"%s\"\n", buf);

    if (feof(tmpf))
        puts("End of file reached");

    return 0;
}
