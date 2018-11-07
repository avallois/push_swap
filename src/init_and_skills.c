/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_skills.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:27:15 by avallois          #+#    #+#             */
/*   Updated: 2018/06/19 20:19:51 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_f(void (*f[13])(t_pm *s, char list, int print))
{
	f[0] = cmd_s;
	f[1] = cmd_s;
	f[2] = cmd_s;
	f[3] = cmd_p;
	f[4] = cmd_p;
	f[5] = cmd_r;
	f[6] = cmd_r;
	f[7] = cmd_r;
	f[8] = cmd_rr;
	f[9] = cmd_rr;
	f[10] = cmd_rr;
}

void	init_s(t_pm **s, int count)
{
	if (!(*s = (t_pm *)malloc(sizeof(t_pm))))
		return ;
	(*s)->a = ft_intnew(count, 0);
	(*s)->b = ft_intnew(count, 0);
	(*s)->med = 0;
	(*s)->alen = 0;
	(*s)->blen = 0;
	(*s)->ste = 0;
	(*s)->nb_i = 0;
}

void	try_simple_skills(t_pm *s)
{
	int *cpy;

	cpy = copy_inttab(s->a, s->alen);
	swap_int(&cpy[0], &cpy[1]);
	if (ft_isascending(cpy, s->alen))
		cmd_s(s, 'a', 1);
	else
	{
		free(cpy);
		cpy = copy_inttab(s->a, s->alen);
		swap_int(&cpy[s->alen - 1], &cpy[s->alen - 2]);
		if (ft_isascending(cpy, s->alen))
		{
			cmd_rr(s, 'a', 1);
			cmd_rr(s, 'a', 1);
			cmd_s(s, 'a', 1);
			cmd_r(s, 'a', 1);
			cmd_r(s, 'a', 1);
		}
	}
	free(cpy);
}
