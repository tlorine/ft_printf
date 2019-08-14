/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:29:29 by tlorine           #+#    #+#             */
/*   Updated: 2019/08/14 15:03:42 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft/libft.h"

# define POZ_1 1
# define POZ_2 2
# define POZ_3 4
# define POZ_4 8
# define POZ_5 16
# define IN_STRUCT(x, f, m, w, a) (x.f = 0, x.m = 0, x.w = 0, x.a = -1)
# define IN_VAR(a, b, c, d) a = 0, b = 0, c = 0, d = 0
# define FLAGS(x) (x == '-' || x == '+' || x == '0' || x == '#' || x == ' ')
# define MOD(x) (x == 'h' || x == 'l' || x == 'L')
# define NUM(x) (x >= '0' && x <= '9')
# define SHIFT_LEFT(x, y) x = x - 1, y = y - 1;
# define STEP_ROUND(m, n, r, o) max--, r = (n[m] - '0') + 1,\
 o = r / 10, n[m] = (r % 10) + '0'
# define ADD(x, y, z) (y = x / 10, z = (x % 10) + '0')
# define LAR_SIZE(x, y, z, s) (s = x > y ? x : y, s = s > z ? s : z)
# define AR_SIM(f, t, c) ((((f & POZ_5) == POZ_5 || (f & POZ_1) == POZ_1) || c == '-') && (t != 'u' && t != 'x' && t != 'X' && t != 'o'))
# define TYPE(x) (x != 'd' &&  x != 'i' && x != 'c' && x != 'e' && x != 'E' && x != 'f'\
&& x != 'g' && x != 'G' && x != 'o' && x != 's' && x != 'S' && x != 'u' && x != 'x' && x != 'X' && x != 'p' && x != 'n' && x != 'b' && x != '\0')

typedef struct s_long_ar
{
    int ost;
    int res;
}              long_ar;


typedef struct	s_params
{
    char    type;
    int     flag;
    int     width;
    int     accur;
    int     mod;
}               params;

typedef struct	s_notation
{
    char    ar;
    int     pointer;
    int     notation;
}               notation;


typedef struct s_fl
{
    unsigned long long int mantisa:64;
    int exp:15;
    int zn:1;
} t_fl;

typedef union u_float
{
    long double d;
    t_fl bits;
}           t_float;

int ft_printf(const char *format, ...);
void put_int(long long int num, params argument, long long int base, char a);
char    *ft_uitoa(unsigned long long int n, long long int base, char a);
params params_arg(const char **format);
int treat_arg (va_list ap, params param);
void    ft_fitoa(long double x, params arg);
void put_float(char *num, int pointer, params arg, int zn);
char *add_float(char *num1, char *num2);
char *power_of(int exp);

#endif