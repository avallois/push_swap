/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:50:45 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:50:46 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cs;

	if (!s)
		return (NULL);
	cs = (char *)s;
	while (*cs != c && *cs)
		cs++;
	if (*cs == c)
		return (cs);
	return (NULL);
}
