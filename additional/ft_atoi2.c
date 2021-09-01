/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:52:48 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/01 19:39:43 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int	ft_atoi2(const char *nptr, int *nbr)
{
	long	n;
	int		sign;
	long	max;

	sign = 1;
	max = 2147483647;
	n = 0;
	if (*nptr == '-')
		sign = -sign;
	if ((*nptr == '-' || *nptr == '+') && *(nptr + 1))
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		if (n > max && sign == 1)
			return (-1);
		if (n > max + 1 && sign == -1)
			return (-1);
		nptr++;
	}
	if (*nptr)
		return (-1);
	n *= sign;
	*nbr = n;
	return (0);
}
