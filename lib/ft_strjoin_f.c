/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:51:39 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:51:40 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strjoin_f(char const *s1, char const *s2, int j)
{
	char	*dest;
	int		i;

	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if ((dest = (char *)malloc(sizeof(dest) * i + 1)) == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	dest = ft_strcat(dest, s2);
	if (j == 1 || j == 3)
		free((void *)s1);
	if (j == 2 || j == 3)
		free((void *)s2);
	return (dest);
}
