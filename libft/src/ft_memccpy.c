/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:34:42 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:19 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t len)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;
	unsigned char		x;

	i = 0;
	dst = (unsigned char *)s1;
	src = (const unsigned char *)s2;
	x = (unsigned char)c;
	while (i < len)
	{
		dst[i] = src[i];
		if (src[i] == x)
			return (++s1);
		i++;
		s1++;
	}
	return (NULL);
}
