/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <aperez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:23:56 by aperez-b          #+#    #+#             */
/*   Updated: 2021/11/04 13:01:34 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_count_words(char *s, char *set, int count)
{
	int		pos;

	pos = ft_strchars_i(s, set);
	if (pos == -1 && !count && s && s[0])
		return (1);
	if (pos == -1 && !count && !s)
		return (0);
	if (!*s)
		return (count);
	if (pos == -1)
		return (count + 1);
	if (&s[pos] != s)
		count++;
	count++;
	return (ft_count_words(&s[pos + 1], set, count));
}

static char	**ft_fill_array(char **aux, int i, char *s, char *set)
{
	int	pos;
	int	len;

	pos = ft_strchars_i(s, set);
	if (pos == -1 && (!s || !s[0]))
		return (aux);
	else if (pos == -1 && s)
	{
		aux[i++] = ft_strdup(s);
		return (aux);
	}
	len = ft_strlen(s) - ft_strlen(&s[pos]);
	if (s != &s[pos])
		aux[i++] = ft_substr(s, 0, len);
	aux[i++] = ft_substr(&s[pos], 0, 1);
	return (ft_fill_array(aux, i, &s[pos + 1], set));
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
