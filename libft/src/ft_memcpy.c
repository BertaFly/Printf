/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:23:24 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:16 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dest != NULL || src != NULL)
	{
		while (i < len)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
		return (dest);
	}
	else
		return (NULL);
}
