/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:55:24 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 05:52:56 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	int		lentotal;

	lentotal = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * lentotal + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	j = -1;
	while (s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (new_str);
}
