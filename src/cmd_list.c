/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:26:47 by avallois          #+#    #+#             */
/*   Updated: 2018/06/20 11:19:35 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		print_infos(t_pm *s, int print)
{
	int i;

	if (print == 1)
	{
		s->nb_i = s->nb_i + 1;
		if ((s->ste == 1 || s->ste == 2) && s->nb_i % 5 == 0)
		{
			i = 0;
			ft_putstr("Liste A: ");
			while (i < s->alen)
			{
				ft_putnbr(s->a[i++]);
				ft_putchar(' ');
			}
			ft_putstr("\n");
			ft_putstr("Liste B: ");
			i = 0;
			while (i < s->blen)
			{
				ft_putnbr(s->b[i++]);
				ft_putchar(' ');
			}
			ft_putstr("\n");
		}
	}
}

void		cmd_rr(t_pm *s, char list, int print)
{
	int		tmp;
	int		j;

	j = (list == 'a') ? s->alen : s->blen;
	if (list == 'c')
	{
		if (print == 1 && s->ste != 4)
			ft_putstr("rrr\n");
		cmd_rr(s, 'a', 0);
		cmd_rr(s, 'b', 0);
		return ;
	}
	print_infos(s, print);
	if (print == 1 && s->ste != 4)
		(list == 'a') ? ft_putstr("rra\n") : ft_putstr("rrb\n");
	tmp = (list == 'a') ? (s->a[s->alen - 1]) : (s->b[s->blen - 1]);
	while (--j > 0)
		(list == 'a') ? s->a[j] = (s->a[j - 1]) :
			(s->b[j] = s->b[j - 1]);
	(list == 'a') ? (s->a[j] = tmp) :
		(s->b[j] = tmp);
}

void		cmd_r(t_pm *s, char list, int print)
{
	int		tmp;
	int		j;

	j = -1;
	if (list == 'c')
	{
		if (print == 1 && s->ste != 4)
			ft_putstr("rr\n");
		cmd_r(s, 'a', 0);
		cmd_r(s, 'b', 0);
		return ;
	}
	print_infos(s, print);
	if (print == 1 && s->ste != 4)
		(list == 'a') ? ft_putstr("ra\n") : ft_putstr("rb\n");
	tmp = (list == 'a') ? (s->a[0]) : (s->b[0]);
	while (++j < (((list == 'a') ? (s->alen - 1) : (s->blen - 1))))
		(list == 'a') ? s->a[j] = (s->a[j + 1]) :
			(s->b[j] = s->b[j + 1]);
	list == 'a' ? (s->a[j] = tmp) :
		(s->b[j] = tmp);
}

void		cmd_s(t_pm *s, char list, int print)
{
	int		tmp;

	if (list == 'c')
	{
		if (print == 1 && s->ste != 4)
			ft_putstr("ss\n");
		cmd_s(s, 'a', 0);
		cmd_s(s, 'b', 0);
		return ;
	}
	if (((list == 'a') ? s->alen : s->blen) < 2)
	{
		if (print == 1)
			(list == 'a') ? ft_putstr("sa\n") : ft_putstr("sb\n");
		return ;
	}
	print_infos(s, print);
	if (print == 1 && s->ste != 4)
		(list == 'a') ? ft_putstr("sa\n") : ft_putstr("sb\n");
	tmp = (list == 'a') ? s->a[0] : s->b[0];
	(list == 'a') ? (s->a[0] = s->a[1]) :
		(s->b[0] = s->b[1]);
	(list == 'a') ? (s->a[1] = tmp) :
		(s->b[1] = tmp);
}

void		cmd_p(t_pm *s, char list, int print)
{
	print_infos(s, print);
	if (((list == 'a') ? s->blen : s->alen) < 1)
	{
		if (print == 1 && s->ste != 4)
			(list == 'a') ? ft_putstr("pa\n") : ft_putstr("pb\n");
		return ;
	}
	if (print == 1 && s->ste != 4)
		(list == 'a') ? ft_putstr("pa\n") : ft_putstr("pb\n");
	if (list == 'a')
	{
		s->alen += 1;
		cmd_rr(s, 'a', 0);
		s->a[0] = s->b[0];
		cmd_r(s, 'b', 0);
		s->blen -= 1;
	}
	else
	{
		s->blen += 1;
		cmd_rr(s, 'b', 0);
		s->b[0] = s->a[0];
		cmd_r(s, 'a', 0);
		s->alen -= 1;
	}
}
