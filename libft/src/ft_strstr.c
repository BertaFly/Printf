/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:51:01 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:33 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *b;
	const char *l;

	l = little;
	if (*little == 0)
		return ((char *)big);
	while (*big != '\0')
	{
		if (*big == *l)
		{
			b = big;
			while (*b == *l || *l == '\0')
			{
				if (*l == '\0')
					return ((char *)big);
				b++;
				l++;
			}
			l = little;
		}
		big++;
	}
	return (NULL);
}
