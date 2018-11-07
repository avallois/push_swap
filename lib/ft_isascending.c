/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:30:24 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:30:26 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_isascending(int *stack, int max)
{
	int i;

	i = 0;
	if (stack)
	{
		while (i < max && (i + 1) != max)
		{
			if (stack[i + 1] < stack[i])
				return (0);
			i++;
		}
	}
	return (1);
}
