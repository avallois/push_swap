/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:29:48 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:29:49 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		*ft_intnew(size_t size, int value)
{
	size_t	i;
	int		*new;

	if ((new = (int *)malloc(sizeof(int) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = value;
		i++;
	}
	return (new);
}
