#include "ft_printf.h"

char	*ft_uitoa(unsigned long long int n, long long int base, char a)
{
	int				i;
	char			*p;
	unsigned long long int	save;

	save = n;
    i = 0;
	i += save == 0 ? 1 : 0;
	while (save > 0)
	{
		save = save / base;
		i++;
	}
	if ((p = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	p[i] = '\0';
	while (save > 0)
	{
        i--;
		p[i] = (n % base) > 9 ? a + (n % base) - 10 : (n % base) + '0';
		n = n / 10;
    }
	return (p);
}
int	treat_u(va_list ap, params param, int base, int a)
{
	if ((param.mod & POZ_1) == POZ_1)
            put_int(va_arg (ap, unsigned long long int), param, base, a);
	else if ((param.mod & POZ_2) == POZ_2)
			put_int(va_arg (ap, unsigned long int), param, base, a);
	else if ((param.mod & POZ_4) == POZ_4)
			put_int((unsigned short)va_arg (ap, int), param, base, a);
	else if ((param.mod & POZ_3) == POZ_3)
			put_int((unsigned char)va_arg (ap, int), param, base, a);
	else
			put_int((unsigned)va_arg(ap, int), param, base, a);
	return (0);
}
int treat_arg (va_list ap, params param)
{
	int base;
	char a;
	base = 10;
	a = 'a';
	if (param.type == 'd' || param.type == 'i' || param.type == 'u' || param.type == 'x' || param.type == 'X' || param.type == 'o' || param.type == 'b')
	{
			if (param.type == 'x' || param.type == 'X' || param.type == 'o' || param.type == 'b')
			{
				if (param.type != 'b')
					base = param.type == 'o' ? 8 : 16;
				else
					base = 2;
				a = param.type == 'x' ? 'a' : 'A';
				treat_u(ap, param, base, a);
			}
			else if (param.type == 'u')
				treat_u(ap, param, base, a);
			else if ((param.mod & POZ_1) == POZ_1)
                put_int(va_arg (ap, long long int), param, base, a);
			else if ((param.mod & POZ_2) == POZ_2)
				put_int(va_arg (ap, long int), param, base, a);
			else if ((param.mod & POZ_4) == POZ_4)
				put_int((short)va_arg (ap, int), param, base, a);
			else if ((param.mod & POZ_3) == POZ_3)
				put_int((char)va_arg (ap, int), param, base, a);
			else
				put_int(va_arg(ap, int), param, base, a);
	}
	else if (param.type == 'e' || param.type == 'E' || param.type == 'f')
	{
		if ((param.mod & POZ_5) == 0)
            ft_fitoa(va_arg(ap, double), param);
		else
			ft_fitoa(va_arg(ap, long double), param);
	}	
	return (0);
}