/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:52:37 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:52:46 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_tabrev(char **tab, int len)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	n = len - 1;
	while (i < n)
	{
		tmp = tab[i];
		tab[i] = tab[n];
		tab[n] = tmp;
		i++;
		n--;
	}
	return (tab);
}
