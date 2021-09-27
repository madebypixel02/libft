/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:47:51 by aperez-b          #+#    #+#             */
/*   Updated: 2021/09/27 16:20:39 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	d = (char *)malloc(size + 1);
	if (!d)
		return (NULL);
	ft_strlcpy(d, s1, size + 1);
	return (d);
}
