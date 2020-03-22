#include <stdio.h>

int main()
{
    int c;
    long nc = 0;

    while ((c = getchar()) != EOF) {
        // EOF: end of file
        putchar(c);
        ++nc;
    }

    printf("\n%ld\n", nc);
}
