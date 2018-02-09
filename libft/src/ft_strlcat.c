/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:05:15 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:27 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_len;
	size_t src_len;
	size_t i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (src_len + size);
	if (dest_len == 0 || dest_len < size)
	{
		i = 0;
		if (size != 0)
		{
			while ((dest_len + i) < (size - 1))
			{
				dest[dest_len + i] = src[i];
				i++;
			}
		}
		dest[dest_len + i] = '\0';
		return (dest_len + src_len);
	}
	else
		return (0);
}
