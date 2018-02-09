/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:55:19 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:29 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	const char	*c;
	char		*d;
	size_t		i;

	d = s1;
	i = 0;
	while (*d)
		d++;
	c = s2;
	while (*c && i < n)
	{
		*d = *c;
		d++;
		c++;
		i++;
	}
	*d = '\0';
	return (s1);
}
