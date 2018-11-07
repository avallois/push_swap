/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdescending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:30:36 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:30:38 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_isdescending(int *stack, int max)
{
	int i;

	i = max - 1;
	if (stack)
	{
		while (i != 0)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i--;
		}
	}
	return (1);
}
