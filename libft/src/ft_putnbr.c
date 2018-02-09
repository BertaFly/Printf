/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:07:17 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/14 16:21:09 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

static void	ft_print_int(int n)
{
	char c;

	if (n > 9)
	{
		ft_print_int(n / 10);
		ft_print_int(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		write(1, "-", 1);
	if (n == -2147483648)
	{
		ft_print_int((ft_abs(n + 1)) / 10);
		write(1, "8", 1);
	}
	else
		ft_print_int(ft_abs(n));
}
