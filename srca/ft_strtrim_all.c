/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:33:57 by aperez-b          #+#    #+#             */
/*   Updated: 2021/10/29 14:08:20 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	malloc_len(char const *s1, char const *set)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s1 && s1[i])
	{
		if (ft_strchr(set, s1[i]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strtrim_all(char const *s1, char const *set)
{
	int		count;
	int		i;
	int		j;
	char	*trimmed;

	j = -1;
	if (!s1)
		return (0);
	i = 0;
	count = malloc_len(s1, set);
	trimmed = malloc(sizeof(char) * (ft_strlen(s1) - count + 1));
	if (!trimmed)
		return (NULL);
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]) && ++j >= 0)
			trimmed[j] = s1[i];
		i++;
	}
	trimmed[++j] = '\0';
	return (trimmed);
}
