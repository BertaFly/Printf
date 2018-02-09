/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:10:53 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:33 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_count_w(const char *s, char c)
{
	size_t count;
	size_t in_str;

	count = 0;
	in_str = 0;
	while (*s)
	{
		if (in_str == 1 && *s == c)
			in_str = 0;
		if (in_str == 0 && *s != c)
		{
			in_str = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static void		ft_free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(&arr[i]);
		i++;
	}
	free(&arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	words;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_count_w((const char *)s, c);
	arr = (char **)malloc(sizeof(*arr) * (words + 1));
	if (!arr)
		return (NULL);
	while (words > 0)
	{
		while (*s == c && *s)
			s++;
		arr[i] = ft_strsub((const char *)s, 0, ft_wordlen((const char *)s, c));
		if (!arr[i])
			ft_free_all(arr);
		s = s + ft_wordlen(s, c);
		i++;
		words--;
	}
	arr[i] = NULL;
	return (arr);
}
