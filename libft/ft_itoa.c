/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:40:27 by tlorine           #+#    #+#             */
/*   Updated: 2019/07/15 14:29:21 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(long long int n, long long int base, char a)
{
	int				i;
	char			*p;
	long long unsigned int	save;
	save = (n < 0 ? n * -1 : n);
	i = (n <= 0 ? 1 : 0);
	while (save > 0)
	{
		save = save / base;
		i++;
	}
	if ((p = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	p[i] = '\0';
	save = (n < 0 ? n * -1 : n);
	while (i-- > 0)
	{
		p[i] = (save % base) > 9 ? a + (save % base) - 10 : (save % base) + '0';
		save = save / base;
		if (n < 0 && i == 1)
			i--;
		if (n < 0 && i == 0)
			p[i] = '-';
	}
	return (p);
}
