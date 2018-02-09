/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:03:09 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:34 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*cpy;
	size_t	j;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (i == ft_strlen(s))
		{
			cpy = ft_strnew(0);
			if (cpy != NULL)
				return (cpy);
		}
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		cpy = ft_strsub(s, (unsigned int)i, j - i + 1);
		if (cpy == NULL)
			return (NULL);
		return (cpy);
	}
	return (NULL);
}
