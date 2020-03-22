#include <stdio.h>

void print_fahr_celsius_table();

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("fahr\tcelsius\n");

    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    printf("\n");

    print_fahr_celsius_table();
    return 0;
}


void print_fahr_celsius_table()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
