/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:23:56 by aperez-b          #+#    #+#             */
/*   Updated: 2021/11/03 21:38:09 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_count_words(char *s, char *needle, int count)
{
	char	*pos;
	int		len;

	len = ft_strlen(needle);
	pos = ft_strnstr(s, needle, ft_strlen(s));
	if (!pos && !count && s && s[0])
		return (1);
	if (!pos && !count && !s)
		return (0);
	if (!*s)
		return (count);
	if (!pos)
		return (count + 1);
	if (pos != s)
		count++;
	count++;
	return (ft_count_words(pos + len, needle, count));
}

static char	**ft_fill_array(char **aux, int i, char *s, char *needle)
{
	char	*pos;
	int		len[2];

	len[0] = ft_strlen(needle);
	pos = ft_strnstr(s, needle, ft_strlen(s));
	if (!pos && (!s || !s[0]))
		return (aux);
	else if (!pos && s)
	{
		aux[i++] = ft_strdup(s);
		return (aux);
	}
	len[1] = ft_strlen(s) - ft_strlen(pos);
	if (s != pos)
		aux[i++] = ft_substr(s, 0, len[1]);
	aux[i++] = ft_strdup(needle);
	return (ft_fill_array(aux, i, pos + len[0], needle));
}

char	**ft_subsplit(char const *s, char *needle)
{
	char	**aux;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_count_words((char *)s, needle, 0);
	aux = malloc((nwords + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux = ft_fill_array(aux, 0, (char *)s, needle);
	aux[nwords] = NULL;
	return (aux);
}
