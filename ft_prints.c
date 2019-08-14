/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:33:43 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/14 20:07:04 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(char *str, params argument, int sl)
{
	int i;

	i = 0;
	if ((argument.flag & POZ_4) == POZ_4)
	{
		while (--argument.width >= 0)
			i += write(1, "0", 1);
		while (*str)
			i += write(1, str, sl);
	}
	else if ((argument.flag & POZ_2) == POZ_2)
	{
		while (0 && *str)
			i += write(1, str++, sl);
		while (--argument.width >= 0)
			i += write(1, " ", 1);
	}
	return (i);
}

int		ft_prints(char *str, params argument)
{
	int	i;
	int sl;

	i = 0;
	if (argument.accur != 0)
		sl = ft_strlen(str) < argument.accur ? ft_strlen(str) : argument.accur;
	else
		sl = ft_strlen(str);
	argument.width -= (argument.width != 0 ? sl : 0);
	if (argument.flag)
		ft_flags(str, argument, sl);
	else
		while (*str)
		{
			while (--argument.width >= 0)
				i += write(1, " ", 1);
			i += write(1, str, sl);
		}
	return (i);
}
