/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:17:30 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/16 20:16:14 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	j = 0;
	length = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (i >= size)
		return (j + size);
	while (i < size - 1 && dst[i])
		i++;
	while (i + length < size - 1 && src[length])
	{
		dst[i + length] = src[length];
		length++;
	}
	dst[i + length] = '\0';
	return (i + j);
}
