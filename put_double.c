/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:07:48 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/17 15:44:23 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *upadate_string(char *num, notation notation, int ost, params arg)
{
	int size;
	int i;
	int i2;
	char *buffer;

	IN_VAR(i, i, i2, i2);
	size = notation.pointer + arg.accur + ((arg.type != 'f' ? 2 : 0)) + (notation.notation < 10 ? 1 : 0);
	if (notation.pointer > 0 && arg.accur > 0)
		size++;
	buffer = ft_if_ost(ost, &i2, size);
	while (i2 < (size - (arg.type != 'f' ? 2 : 0)) - (notation.notation < 10 ? 1 : 0) && num[i] != '\0')
	{
		REALNO(buffer[i2], num[i], i2, i);
		if (i == notation.pointer + ost && arg.accur > 0 && notation.pointer > 0)
		{
			buffer[i2] = '.';
			i2++;
		}
	}
	while (num[i] == '\0' && i2 < (size - (arg.type != 'f' ? 2 : 0)) - (notation.notation < 10 ? 1 : 0))
	{
		buffer[i2] = '0';
		i2++;
	}
	return (if_e(arg, notation, buffer, i2));
}

int rounding(char *num, int *pointer, params arg)
{
	int size_str;
	int max;
	int check_ost;
	long_ar la;

	size_str = ft_strlen(num);
	max = *pointer + arg.accur;
	if (*pointer + arg.accur >= size_str || max - 1 == -1 || num[max] < '5')
		return (0);
	check_ost = max;
	while (num[check_ost] != '\0' && num[max] == '5')
	{
		check_ost++;
		if (num[check_ost] != '\0' && num[check_ost] != '0')
			break;
	}
	if (num[max] == '5')
		check_ost = num[check_ost] == '\0' ? 0 : 1;
	if (((num[max - 1] - '0') % 2 != 0 && num[max] == '5') || num[max] > '5' || check_ost == 1)
		STEP_ROUND(max, num, la.res, la.ost);
	while (la.ost != 0 && max != 0)
		STEP_ROUND(max, num, la.res, la.ost);
	if (la.ost != 0 && max == 0)
		return (1);
	return (0);
}

int put_ar_float(params argument, int zn)
{
	if (zn == -1)
	{
		write(1, "-", 1);
		return (1);
	}
	else if ((POZ_1 & argument.flag) == POZ_1)
	{
		write(1, " ", 1);
		return (1);
	}
	else if ((POZ_5 & argument.flag) == POZ_5)
	{
		if (zn == -1)
		write(1, "-", 1);
		else
			write(1, "+", 1);
		return (1);
	}
	return (0);
}

void    float_flags(char* buffer, params arg, int zn)
{
	int sl;

	sl = ft_strlen(buffer);
	if ((arg.flag & POZ_1) == POZ_1 || zn < 0 || (arg.flag & POZ_5) == POZ_5)
		sl++;
	while (arg.width - sl > 0 && !POZ_4)
	{
			write(1, " ", 1);
			arg.width--;
	}
	put_ar_float(arg,  zn);
	while (arg.width - sl > 0 && sl < arg.width && (arg.flag & POZ_4) == POZ_4 && (arg.flag & POZ_2) == 0)
	{
		write(1, "0", 1);
		arg.width--;
	}
	write(1, buffer, sl);
	while (arg.width - sl > 0 && sl < arg.width && (arg.flag & POZ_2) == POZ_2)
	{
		write(1, " ", 1);
		arg.width--;
	}
}

void put_float(char *num, int pointer, params arg, int zn)
{
	int i;
	notation notation;
	int check_ost;
	char *buffer;

	notation.ar = '+';
	notation.pointer = pointer;
	i = 0;
	while ((arg.type == 'e' || arg.type == 'E') && num[i] == '0')
	{
		i++;
		notation.ar = '-';
	}
	notation.notation = (i != 0 ? i : notation.pointer - 1);
	num = num + i;
	if (arg.type == 'e' || arg.type == 'E')
		notation.pointer = 1;
	buffer = upadate_string(num, notation, rounding(num, &notation.pointer, arg), arg);
	float_flags(buffer, arg, zn);
	buffer = ft_strdel(&buffer);
	return ;
}
