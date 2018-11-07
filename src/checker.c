/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:26:33 by avallois          #+#    #+#             */
/*   Updated: 2018/06/18 21:42:38 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			print_answer(t_pm *s, int *a, int alen)
{
	quicksort(a, 0, alen - 1);
	if (ft_inttab_cmp(s->a, s->alen, a, alen) != -1)
	{
		ft_putstr("KO\n");
		return ;
	}
	else
		ft_putstr("OK\n");
	return ;
}

char			select_list(char **list, int i)
{
	int			len;

	len = ft_strlen(list[i]);
	if (list[i][len - 1] == 'r')
		return ('c');
	else
		return (list[i][len - 1]);
}

void			run_checker(t_pm *s)
{
	int			i;
	char		*line;
	void		(*f[13])(t_pm *, char, int);
	static char	*cmd_list[12] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", NULL};

	i = 0;
	line = NULL;
	init_f(f);
	while (get_next_line(0, &line) > 0)
	{
		if ((i = pos_str_tab(line, cmd_list)) >= 0)
			f[i](s, select_list(cmd_list, i), 0);
		else
			ft_error();
		free(line);
	}
}

int				main(int argc, char **argv)
{
	t_pm		*s;
	int			*copy;
	int			copylen;
	int			count;

	if (argc == 1)
		ft_putstr("\0");
	else
	{
		count = count_numbers(argv);
		init_s(&s, count);
		s = fill_struct(s, argv);
		copy = copy_inttab(s->a, s->alen);
		copylen = s->alen;
		run_checker(s);
		print_answer(s, copy, copylen);
		free(copy);
		ft_free_stacks(s);
	}
	return (0);
}
