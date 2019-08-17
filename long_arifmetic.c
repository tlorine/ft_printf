/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arifmetic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:12:44 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/17 16:37:47 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int count_num(char *num1, char *num2, int len1, int len2)
{
	int size;
	long_ar la;

	IN_VAR(size, la.ost, la.res, size);
	while(len2 > len1)
	{
		len2--;
		size++;
	}
	while (len2 > -1 || len1 > -1)
	{
		if (len1 >= 0 && len2 >= 0)
			la.res = ((num1[len1] - '0') + (num2[len2] - '0')) + la.ost;
		else
			la.res = (num1[len1] - '0') + la.ost;
		la.ost = la.res / 10;
		SHIFT_LEFT(len1, len2);
		size++;
	}
	if (la.ost != 0)
		size++;
	return (size);
}

char *add_float(char *num1, char *num2)
{
	afloat af;
	long_ar la;

	if(num1 == NULL)
		return (ft_strdup(num2));
	alloc_result(&af, &la, num1, num2);
	while (af.len2 > -1 || af.len1 > -1)
	{
		if (af.len1 > -1 && af.len2 > -1)
			la.res = ((num1[af.len1] - '0') + (num2[af.len2] - '0')) + la.ost;
		else
			la.res = af.len1 > af.len2 ? (num1[af.len1] - '0') + la.ost : (num2[af.len2] - '0') + la.ost;
		ADD(la.res, la.ost, af.result[af.size]);
		SHIFT_LEFT(af.len1, af.len2);
		af.size--;
	}
	if (la.ost != 0)
		af.result[af.size] = la.ost + '0';
	return(af.result);
}

char  *h_update(char *p, int size, int exp)
{
	int save = size;
	char *h;
	h = (char *)ft_memalloc((sizeof(char) * (size + (exp > 0 ? exp : 0)) + 1));
	ft_bzero(h, size + (exp > 0 ? exp : 0) + 1);
	if (h == NULL)
		return (NULL);
	size = 0;
	while (exp > 0)
	{
		h[size] = '0';
		size++;
		exp--;
	}
	while (save > 0)
	{
		save--;
		h[size] = p[save];
		size++;
	}
	h[size] = '\0';
	return (h);
}

char *multipl(char *p, int exp, int save, int st)
{
    int i;
    long_ar la;

    while (exp > 0)
    {
        IN_VAR(la.res, la.res, la.ost, i);
        while(p[i] != '\0')
        {
            la.res = ((p[i] - '0') * st) + la.ost;
            ADD(la.res, la.ost, p[i]);
            i++;
            if (p[i] == '\0' && la.ost != 0)
            {
                ADD(la.ost, la.res, p[i]);
                i++;
                p[i] = '\0';
            }
        }
        p[i] = '\0';
        exp--;
    }
    return (h_update(p, i == 0 ? 1 : i, save - i));
}
char *power_of(int exp)
{
    int st = exp < 0 ? 5 : 2;
    int save;
    int i;
    char p[10000];

    IN_VAR(save, save, i, i);
    p[0] = '1';
    p[1] = '\0';
    if (exp < 0)
    {
         exp = exp * -1;
         save = exp;
    }
    return(multipl(p, exp, save, st));
}
