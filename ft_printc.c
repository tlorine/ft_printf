/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:15:40 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/16 18:42:10 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printc(int simnum, params argument)
{
	unsigned char	sim;
	int				i;

	sim = simnum;
	i = 0;
	if ((argument.flag & POZ_2) == POZ_2)
	{
		i += write(1, &sim, 1);
		while (--argument.width > 0)
			i += write(1, " ", 1);
	}
	else
	{
		while (--argument.width > 0)
			i += write(1, " ", 1);
		i += write(1, &sim, 1);
	}
	return (i);
}
