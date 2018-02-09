/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:54:26 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:28 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*map;
	unsigned int	i;

	if (!f || !s)
		return (0);
	map = ft_strdup(s);
	if (!map)
		return (0);
	i = 0;
	while (s[i])
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
