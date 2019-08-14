/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:21:23 by tlorine           #+#    #+#             */
/*   Updated: 2019/08/14 16:28:46 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	va_list ap;
	params argument;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			int s;
			argument = params_arg(&format);
			treat_arg(ap, argument);
		}
		else
		{
			write(1, format, 1);
			++format;
		}
	}
	va_end(ap);
	return (0);
}