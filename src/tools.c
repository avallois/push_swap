/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:28:30 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:28:32 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_stacks(t_pm *s)
{
	free(s->a);
	free(s->b);
	free(s);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_isint(char *str, t_pm *s)
{
	if (ft_strlen(str) > 11)
	{
		ft_free_stacks(s);
		ft_error();
	}
	else if (ft_long_atoi(str) > 2147483647 || ft_long_atoi(str) < -2147483648)
	{
		ft_free_stacks(s);
		ft_error();
	}
}

void	ft_isduplicate(int n, t_pm *s)
{
	int i;

	i = 0;
	while (i < s->alen)
	{
		if (s->a[i] == n)
		{
			ft_free_stacks(s);
			ft_error();
		}
		i++;
	}
}

int		count_numbers(char *argv[])
{
	int i;
	int p;
	int count;

	count = 0;
	i = 0;
	while (argv[i])
	{
		p = 0;
		while (argv[i][p])
		{
			if (ft_isdigit(argv[i][p]) || argv[i][p] == '-')
			{
				count++;
				while (ft_isdigit(argv[i][p]) || argv[i][p] == '-')
					p++;
			}
			else
				p++;
		}
		i++;
	}
	return (count);
}
