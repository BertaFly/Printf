/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:22:54 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:15 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char*)dest;
	s = (char*)src;
	i = 0;
	if (d != NULL || s != NULL)
	{
		if (s < d)
		{
			while (n--)
				d[n] = s[n];
		}
		else
			ft_memcpy(d, s, n);
		return (d);
	}
	else
		return (NULL);
}
