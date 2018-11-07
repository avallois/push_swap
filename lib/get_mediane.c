/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:52:57 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:52:59 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			get_mediane(int *a, int alen)
{
	int		*cpy;
	int		med;

	cpy = NULL;
	if (alen == 2)
		med = a[0] < a[1] ? a[0] : a[1];
	else
	{
		cpy = copy_inttab(a, alen);
		quicksort(cpy, 0, alen - 1);
		med = cpy[(alen / 2)];
	}
	if (cpy)
		free(cpy);
	return (med);
}
