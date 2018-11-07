/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:51:25 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:51:26 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	if ((dest = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	while (j < i)
	{
		dest[j] = s[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
