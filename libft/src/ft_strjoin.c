/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:39:11 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:36 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	joined_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!joined_str)
		return (NULL);
	ft_strcat(joined_str, s1);
	ft_strcat(joined_str, s2);
	return (joined_str);
}
