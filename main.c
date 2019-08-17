#include "ft_printf.h"
#include <float.h>
int main()
{
    //ft_printf("%d\n %d\n %f f\n%d d\n%c c\n %x x\n %e e\n %b b\n %s s\n %f\n", 123.123, 43, 54, 10, 344.343, 343, "sssssssss", 123.123);
    //ft_printf("%f", 123.123);
    //ft_printf("%f", 123.123);
    ft_printf("%s s\n%f f\n%c c\n %d d\n %x x\n %e e\n %d b\n", "asdasdasda", 43.323, 97, 54, 10, 344.343, 343);
    printf("%s s\n%f f\n%c c\n %d d\n %x x\n %e e\n %d b\n", "asdasdasda", 43.323, 97, 54, 10, 344.343, 343);
    //ft_printf("%f", 43.323);
    //printf("%.10f", LDBL_MAX);
}