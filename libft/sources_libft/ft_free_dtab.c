/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:59:55 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/14 04:59:31 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_dtab(char **dtab)
{
	int	i;

	i = 0;
	if (!dtab[i])
		return ;
	while (dtab[i] && dtab[i] != NULL)
	{
		free(dtab[i]);
		i++;
	}
	free(dtab);
}
