/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:59:29 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/17 16:51:52 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int arg_flags(const char **format, int *flag)
{
	if (**format == ' ' && (*flag & POZ_5) == 0)
		*flag = *flag | POZ_1;
	else if (**format == '-')
	{
		*flag = *flag | POZ_2;
		if ((*flag & POZ_4) == 1)
			*flag ^= POZ_4;
	}
	else if (**format == '#')
		*flag = *flag | POZ_3;
	else if (**format == '0' && (*flag & POZ_2) == 0)
		*flag = *flag | POZ_4;
	else if (**format == '+')
	{
		*flag = *flag | POZ_5;
		if ((*flag & POZ_1) == 1)
			*flag ^= POZ_1;
	}
	return (*flag);
}

void arg_mod(const char **format, int *mod)
{
	*mod = 0;
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		*mod |= POZ_1;
		++(*format);
	}
	else if (**format == 'l')
		*mod |= POZ_2;
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		*mod |= POZ_3;
		++(*format);
	}
	else if (**format == 'h')
		*mod |= POZ_4;
	else if (**format == 'L')
		*mod |= POZ_5;
}

void arg_accur(const char **format, int *accur)
{
	if (NUM(*(*format + 1)))
	{
		++(*format);
		*accur = ft_atoi((char *)*format);
		while(NUM(*(*format + 1)))
			++(*format);
	}
	else
		*accur = 0;
}

void arg_width(const char **format, int *width)
{
	*width = ft_atoi((char *)*format);
	while(NUM(*(*format + 1)))
		++(*format);
}
params params_arg(const char **format)
{
	params argument;

	IN_STRUCT(argument, flag, mod, width, accur);
	while (TYPE(**format) && **format != '\0')
	{
		if (FLAGS(**format))
			arg_flags(format, &argument.flag);
		else if (**format == '.')
			arg_accur(format, &argument.accur);
		else if (MOD(**format))
			arg_mod(format, &argument.mod);
		else if (NUM(**format))
			arg_width(format, &argument.width);
		++(*format);
	}
	argument.type = **format;
	if (argument.accur == -1 && (argument.type == 'f' || argument.type == 'E' || argument.type == 'e'))
		argument.accur = 6;
	else if(argument.accur == -1)
		argument.accur = 0;
	++(*format);
	return (argument);
}
