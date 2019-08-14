#include "ft_printf.h"
#include <float.h>
int main()
{
    ft_printf("%Lf\n\n\n", LDBL_MAX);
    printf("%Lf", LDBL_MAX);
}