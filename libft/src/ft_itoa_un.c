/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:44:12 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/05 21:30:14 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long long	ft_len(unsigned long long nbr)
{
	long long	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa_un(unsigned long long nbr)
{
	long long	len;
	char		*c;

	len = ft_len(nbr);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	if (nbr == 0)
		c[len + 1] = '\0';
	else
	{
		c[len] = '\0';
		len--;
	}
	while (len > -1)
	{
		c[len] = '0' + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	return (c);
}
