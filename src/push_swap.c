/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:27:38 by avallois          #+#    #+#             */
/*   Updated: 2018/06/20 11:21:02 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_pusha(t_pm *s)
{
	int		i;
	int		j;
	int		index;
	int		min_action;
	int		k;

	k = s->blen;
	i = -1;
	j = 0;
	index = 0;
	min_action = 9999;
	while (++i != k)
		simule_insert_a(s, &min_action, &index, i);
	put_instructions_v(s, index, min_action);
	if (s->a[0] > s->a[1])
		cmd_s(s, 'a', 1);
}

void		create_b(t_pm *s)
{
	int		i;
	int		j;
	int		bmed;

	if (s->alen == 1)
		return ;
	s->med = get_mediane(s->a, s->alen);
	j = s->alen;
	i = -1;
	while (++i <= j)
	{
		if (s->a[0] < s->med)
		{
			cmd_p(s, 'b', 1);
			bmed = get_mediane(s->b, s->blen);
			if (s->b[0] <= bmed)
				cmd_r(s, 'b', 1);
		}
		else
			cmd_r(s, 'a', 1);
	}
}

void		replace_list(t_pm *s, int refa)
{
	int		i;

	i = 0;
	while (s->a[i] != refa)
		i++;
	if (i > s->alen / 2)
		while (s->a[s->alen - 1] != refa)
			cmd_rr(s, 'a', 1);
	else
		while (s->a[s->alen - 1] != refa)
			cmd_r(s, 'a', 1);
}

void		run_algo(t_pm *s)
{
	int refa;

	if (s->alen > 1)
		try_simple_skills(s);
	if (ft_isascending(s->a, s->alen))
		return ;
	if (s->alen > 15)
	{
		while (s->alen > 2)
			create_b(s);
		if (s->a[0] > s->a[1])
			cmd_s(s, 'a', 1);
		refa = s->a[1];
		while (s->blen != 0)
			ft_pusha(s);
		replace_list(s, refa);
	}
	else
		sort_short_lists(s);
}

int			main(int argc, char **argv)
{
	t_pm	*s;
	int		count;

	if (argc == 1)
		ft_putstr("\0");
	else
	{
		count = count_numbers(argv);
		init_s(&s, count);
		s = fill_struct(s, argv);
		run_algo(s);
		if ((s->ste == 3 || s->ste == 2 || s->ste == 4))
		{
			ft_putstr("Nombre d'instructions: ");
			ft_putnbr(s->nb_i);
			ft_putchar('\n');
		}
		ft_free_stacks(s);
	}
	return (0);
}
