/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:52:48 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/21 23:08:51 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int	ft_atoi2(const char *nptr, long *nbr)
{
	int		sign;
	long	max;

	sign = 1;
	max = 2147483647;
	*nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -sign;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (!ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*nbr = 10 * *nbr + (*nptr - '0');
		if (*nbr > max && sign == 1)
			return (-1);
		if (*nbr > max + 1 && sign == -1)
			return (-1);
		nptr++;
	}
	if (*nptr && !ft_isspace(*nptr))
		return (-1);
	*nbr *= sign;
	return (0);
}
