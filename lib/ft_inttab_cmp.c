/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:30:03 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:30:04 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_inttab_cmp(int *a, int alen, int *b, int blen)
{
	int	i;

	i = 0;
	while (i < alen && i < blen)
	{
		if (a[i] - b[i] != 0)
			return (i);
		else
			i++;
	}
	if (i < alen || i < blen)
		return (i);
	return (-1);
}
