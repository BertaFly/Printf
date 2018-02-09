/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:27:52 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:32 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = s;
	tmp = tmp + ft_strlen(s);
	while (*tmp != (char)c && tmp != s)
		tmp--;
	if (*tmp == (char)c)
		return ((char *)tmp);
	return (NULL);
}
