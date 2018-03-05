/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:59:15 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/05 21:28:37 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long long	ft_abs(long long nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

static long long	ft_len(long long nbr)
{
	int			len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(long long nbr)
{
	long long	len;
	long long	sign;
	char		*c;

	sign = (nbr < 0) ? -1 : 1;
	len = ft_len(nbr);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (!c)
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(nbr % 10);
		nbr = ft_abs(nbr / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
