/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:27:00 by avallois          #+#    #+#             */
/*   Updated: 2018/06/20 11:15:22 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*add_ifvalid(t_pm *s, char *nb, int *n)
{
	if (nb)
	{
		ft_isint(nb, s);
		ft_isduplicate(ft_long_atoi(nb), s);
		s->a[(*n)++] = ft_long_atoi(nb);
		s->alen = s->alen + 1;
		free(nb);
		nb = NULL;
	}
	return (nb);
}

char	*concat_nbchar(char *nb, char *arg, int *p)
{
	char tmp[2];

	if (nb == NULL)
		nb = ft_strdup("\0");
	tmp[0] = arg[*p];
	tmp[1] = '\0';
	nb = ft_strjoin_f(nb, tmp, 1);
	(*p)++;
	return (nb);
}

void	treat_arg(t_pm *s, char *nb, int *n, char *arg)
{
	int p;

	p = 0;
	while (arg[p])
	{
		if ((!ft_isdigit(arg[p]) && arg[p] != ' ' &&
		arg[p] != '-') || (arg[p] == '-'
		&& !ft_isdigit(arg[p + 1])) ||
		(ft_isdigit(arg[p]) && arg[p + 1] == '-'))
		{
			ft_free_stacks(s);
			ft_error();
		}
		else if (arg[p] == ' ')
		{
			nb = add_ifvalid(s, nb, &(*n));
			while (arg[p] == ' ')
				p++;
		}
		else if (ft_isdigit(arg[p]) || arg[p] == '-')
			nb = concat_nbchar(nb, arg, &p);
		else
			p++;
	}
	nb = add_ifvalid(s, nb, &(*n));
}

t_pm	*fill_struct(t_pm *s, char *a[])
{
	int		i;
	char	*nb;
	int		n;

	nb = NULL;
	n = 0;
	i = 1;
	if (!ft_strcmp(a[1], "-v") || !ft_strcmp(a[1], "-vi") ||
			!ft_strcmp(a[1], "-i") || !ft_strcmp(a[1], "-iv") ||
			!ft_strcmp(a[1], "-im") || !ft_strcmp(a[1], "-mi"))
		i = 2;
	if ((!ft_strcmp(a[1], "-v") && a[2]))
		s->ste = 1;
	if ((!ft_strcmp(a[1], "-vi") && a[2]) || (!ft_strcmp(a[1], "-iv") && a[2]))
		s->ste = 2;
	if ((!ft_strcmp(a[1], "-i") && a[2]))
		s->ste = 3;
	if ((!ft_strcmp(a[1], "-im") && a[2]) || (!ft_strcmp(a[1], "-mi") && a[2]))
		s->ste = 4;
	while (a[i])
		treat_arg(s, nb, &n, a[i++]);
	if (nb)
		free(nb);
	return (s);
}
