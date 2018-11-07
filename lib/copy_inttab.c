/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_inttab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:29:20 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:29:22 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			*copy_inttab(int *a, int alen)
{
	int		i;
	int		*dest;

	i = -1;
	dest = ft_intnew(alen, 0);
	while (++i < alen)
		dest[i] = a[i];
	return (dest);
}
