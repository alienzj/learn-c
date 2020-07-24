#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void print_fahr_celsius_table();

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    fahr = LOWER;

    printf("fahr\tcelsius\n");

    while (fahr <= UPPER)
    {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    printf("\n");

    print_fahr_celsius_table();
    return 0;
}

void print_fahr_celsius_table()
{
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
        printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
