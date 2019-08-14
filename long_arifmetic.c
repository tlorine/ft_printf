/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arifmetic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:12:44 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/14 17:41:31 by dsandshr         ###   ########.fr       */
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
	int len1;
	int len2;
	int size;
	long_ar la;

	IN_VAR(la.ost, la.ost, len1, len2);
	char *result;
	if(num1 == NULL)
		return (ft_strdup(num2));
	len1 = ft_strlen(num1) - 1;
	len2 = ft_strlen(num2) - 1;
	size = count_num(num1, num2, len1, len2);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	size--;
	while (len2 > len1)
	{
		result[size] = num2[len2];
		SHIFT_LEFT(len2, size);
	}
	while (len2 > -1 || len1 > -1)
	{
		if (len1 > -1 && len2 > -1)
			la.res = ((num1[len1] - '0') + (num2[len2] - '0')) + la.ost;
		else
			la.res = len1 > len2 ? (num1[len1] - '0') + la.ost : (num2[len2] - '0') + la.ost;
		ADD(la.res, la.ost, result[size]);
		SHIFT_LEFT(len1, len2);
		size--;
	}
	if (la.ost != 0)
		result[size] = la.ost + '0';
	return(result);
}

char  *h_update(char *p, int size, int exp)
{
	int save = size;
	char *h;
	h = (char *)ft_memalloc((sizeof(char) * (size + (exp > 0 ? exp : 0)) + 1));
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

char *power_of(int exp)
{
	int st = exp < 0 ? 5 : 2;
	int save;
	int i;
	char p[10000];
	char *h;
	long_ar la;

	IN_VAR(la.res, save, la.ost, i);
	p[0] = '1';
	p[1] = '\0';
	if (exp < 0)
	{
		exp = exp * -1;
		save = exp;
	}
	while (exp > 0)
	{
		i = 0;
		while(p[i] != '\0')
		{
			la.res = ((p[i] - '0') * st) + la.ost;
			ADD(la.res, la.ost, p[i]);
			i++;
			if (p[i] == '\0' && la.ost != 0)
			{
				p[i] = la.ost + '0';
				la.ost = 0;
				i++;
				p[i] = '\0';
			}
		}
		p[i] = '\0';
		exp--;
	}
	return (h_update(p, i == 0 ? 1 : i, save - i));
}
