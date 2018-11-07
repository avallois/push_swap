/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_str_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:53:59 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:54:01 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		pos_str_tab(char *haystack, char **needle)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (ft_strcmp(haystack, needle[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
