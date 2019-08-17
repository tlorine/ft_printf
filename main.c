#include "ft_printf.h"
#include <float.h>
int main()
{
    //ft_printf("%d\n %d\n %f f\n%d d\n%c c\n %x x\n %e e\n %b b\n %s s\n %f\n", 123.0123, 43, 54, 10, 344.0343, 343, "sssssssss", 123.0123);
    //ft_printf("%f", 123.0123);
    //ft_printf("%f", 123.0123);
    ft_printf("\n%%1s s\n%.0f f\n%.c c\n %.0d d\n %.0x x\n %.0e e\n %.0d b\n\n\n\n", "asdasdasda", 43.0323, 97, 54, 10, 344.0343, 343);
    printf("%%1s s\n%.0f f\n%.c c\n %.0d d\n %.0x x\n %.0e e\n %.0d b\n", "asdasdasda", 43.0323, 97, 54, 10, 344.0343, 343);
    //ft_printf("%f", 43.0323);
    //printf("%.010f", LDBL_MAX);
}