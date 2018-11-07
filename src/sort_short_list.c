/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:28:08 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:28:09 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	place_first_elt(t_pm *s, int *sort_done)
{
	int j;

	j = 0;
	while (sort_done[0] != s->a[j])
		j++;
	if ((s->alen - 1 - j) <= j)
	{
		while (s->a[s->alen - 1] != sort_done[0])
			cmd_rr(s, 'a', 1);
	}
	else
	{
		while (s->a[s->alen - 1] != sort_done[0])
			cmd_r(s, 'a', 1);
	}
}

int		swap_and_place(t_pm *s)
{
	int isin;

	cmd_s(s, 'a', 1);
	cmd_r(s, 'a', 1);
	isin = 1;
	return (isin);
}

int		take_and_place(t_pm *s, int *sort_done, int i)
{
	int isin;
	int j;

	j = 0;
	isin = 0;
	while (j < s->blen)
	{
		if (s->b[j] == sort_done[i])
		{
			while (j > 0)
			{
				cmd_r(s, 'b', 1);
				j--;
			}
			cmd_p(s, 'a', 1);
			cmd_r(s, 'a', 1);
			isin = 1;
			break ;
		}
		j++;
	}
	return (isin);
}

void	place_all_elts(t_pm *s, int *sort_done)
{
	int i;
	int isin;
	int len;

	i = 1;
	len = s->alen;
	while (i < len)
	{
		if (s->a[0] == sort_done[i])
			cmd_r(s, 'a', 1);
		else
		{
			isin = 0;
			if (s->a[1] == sort_done[i])
				isin = swap_and_place(s);
			else
				isin = take_and_place(s, sort_done, i);
			if (isin == 0)
			{
				cmd_p(s, 'b', 1);
				i--;
			}
		}
		i++;
	}
}

void	sort_short_lists(t_pm *s)
{
	int *sort_done;

	sort_done = copy_inttab(s->a, s->alen);
	quicksort(sort_done, 0, s->alen - 1);
	place_first_elt(s, sort_done);
	place_all_elts(s, sort_done);
	free(sort_done);
}
