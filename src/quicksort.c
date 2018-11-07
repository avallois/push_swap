/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:27:50 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:27:51 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_define_pivot(int *tab, int low, int high)
{
	(void)tab;
	(void)high;
	(void)low;
	return (high);
}

long	ft_partition(int *tab, int low, int high, int pivot)
{
	int i;
	int j;

	if (high != pivot)
		swap_int(&tab[high], &tab[pivot]);
	i = low;
	j = low;
	while (j < high)
	{
		if (tab[j] <= tab[high])
		{
			if (i != j)
				swap_int(&tab[i], &tab[j]);
			i++;
		}
		j++;
	}
	if (high != i)
		swap_int(&tab[i], &tab[high]);
	return (i);
}

void	quicksort(int *tab, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = ft_define_pivot(tab, low, high);
		pivot = ft_partition(tab, low, high, pivot);
		quicksort(tab, low, pivot - 1);
		quicksort(tab, pivot + 1, high);
	}
}
