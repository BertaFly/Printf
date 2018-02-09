/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:37:17 by inovykov          #+#    #+#             */
/*   Updated: 2018/01/09 12:47:29 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;
	char	*d;

	len = ft_strlen(s1);
	dst = ft_strnew(len);
	if (!dst)
		return (0);
	d = dst;
	while (*s1)
		*d++ = *s1++;
	*d = 0;
	return (dst);
}
