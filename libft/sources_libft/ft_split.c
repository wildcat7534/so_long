/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:38:02 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/13 01:23:02 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_word_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free_split(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return ((void *)0);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	**tab_str;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	tab_str = (char **)malloc(sizeof(char *) * (ft_nb_words(str, c) + 1));
	if (!tab_str)
		return (NULL);
	while (++i < ft_nb_words(str, c))
	{
		while (str[j] && str[j] == c)
			j++;
		tab_str[i] = ft_substr(str, j, ft_word_len(&str[j], c));
		if (!tab_str[i])
			return (ft_free_split(tab_str, i));
		while (str[j] && str[j] != c)
			j++;
	}
	tab_str[i] = NULL;
	return (tab_str);
}
