/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:27:28 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:27:29 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	place_shots(t_pm *s, int shots)
{
	while (shots > 1)
	{
		cmd_r(s, 'a', 1);
		(shots)--;
	}
	cmd_p(s, 'a', 1);
}

void	place_rev_shots(t_pm *s, int shots)
{
	while (shots > 1)
	{
		cmd_rr(s, 'a', 1);
		(shots)--;
	}
	cmd_p(s, 'a', 1);
}

void	put_instructions_v(t_pm *s, int index, int shots)
{
	int	neg;

	neg = (shots >= 0) ? 0 : 1;
	shots = (shots >= 0) ? shots : shots * -1;
	while (index > 0)
	{
		cmd_r(s, 'b', 1);
		shots--;
		index--;
	}
	if (shots == 2 && neg == 0)
	{
		cmd_p(s, 'a', 1);
		cmd_s(s, 'a', 1);
		return ;
	}
	neg == 1 ? place_rev_shots(s, shots) : place_shots(s, shots);
}

int		count_shots(t_pm *s, int n)
{
	int i;
	int i2;

	i = 0;
	while (s->b[n] > s->a[i])
		i++;
	i2 = i + 1;
	while ((i2 + 1) != s->alen && s->a[i2] < s->a[i2 + 1])
		i2++;
	if (i2 + 1 != s->alen && s->a[i2] > s->a[i2 + 1])
	{
		i2++;
		if (s->b[n] >= s->a[i2])
		{
			while (i2 + 1 != s->alen
					&& s->b[n] > s->a[i2] && s->b[n] > s->a[i2 + 1])
				i2++;
		}
	}
	if (i2 + 1 != s->alen || (i2 == s->alen - 1 && s->a[i2] > s->b[n]
		&& s->a[i2 - 1] > s->a[i2]))
		i = i2;
	return (i);
}

void	simule_insert_a(t_pm *s, int *min, int *index, int n)
{
	int	mincpy;
	int	i;

	i = count_shots(s, n);
	mincpy = *min < 0 ? *min * -1 : *min;
	if (i == s->alen && mincpy > (2 + n))
	{
		*index = n;
		*min = (1 + n) * -1;
		return ;
	}
	else if (i > (s->alen / 2) && mincpy > (n + s->alen - i + 1))
	{
		*min = (s->alen - i + 1 + n) * -1;
		*index = n;
	}
	else if (mincpy > (i + 1 + n))
	{
		*min = i + 1 + n;
		*index = n;
	}
}
