/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:49:53 by avallois          #+#    #+#             */
/*   Updated: 2018/06/13 21:50:28 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	char	*csrc;

	i = ft_strlen(dest);
	csrc = (char *)src;
	while (*csrc)
	{
		dest[i] = *csrc;
		i++;
		csrc++;
	}
	dest[i] = '\0';
	return (dest);
}
