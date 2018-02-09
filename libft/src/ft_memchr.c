/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:30:58 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:18 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char		x;
	size_t				i;

	x = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		if (((unsigned char *)s)[i] == x)
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}
