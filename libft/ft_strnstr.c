/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:07:33 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/11 19:49:37 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	k;
	size_t	j;

	i = 0;
	j = 0;
	k = 0;
	if (needle[j] == '\0' || (haystack[0] == '\0' && needle[0] == '\0'))
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + k] == needle[j] && k + i < len && needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)haystack + i);
		j = 0;
		k = 0;
		i++;
	}
	return (0);
}
