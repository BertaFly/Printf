/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:10:21 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 20:10:29 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		put_uni_char(unsigned int a, char **tmp)
{
	unsigned char	octet;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	o3;
	unsigned char	o4;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	if (a <= 127)
	{
		octet = a;
		tmp[0][0] = octet;
		return (1);
	}
	else if (a <= 2047)
	{
		o2 = (a << 26) >> 26;
		o1 = ((a >> 6) << 27) >> 27;
		octet = (mask1 >> 8) | o1;
		tmp[0][0] = octet;
		octet = ((mask1 << 24) >> 24) | o2;
		tmp[0][1] = octet;
		return (2);
	}
	else if (a <= 65535)
	{
		o3 = (a << 26) >> 26;
		o2 = ((a >> 6) << 26) >> 26;
		o1 = ((a >> 12) << 28) >> 28;
		octet = (mask2 >> 16) | o1;
		tmp[0][0] = octet;
		octet = ((mask2 << 16) >> 24) | o2;
		tmp[0][1] = octet;
		octet = ((mask2 << 24) >> 24) | o3;
		tmp[0][2] = octet;
		return (3);
	}
	else
	{
		o4 = (a << 26) >> 26;
		o3 = ((a >> 6) << 26) >> 26;
		o2 = ((a >> 12) << 26) >> 26;
		o1 = ((a >> 18) << 29) >> 29;
		octet = (mask3 >> 24) | o1;
		tmp[0][0] = octet;
		octet = ((mask3 << 8) >> 24) | o2;
		tmp[0][1] = octet;
		octet = ((mask3 << 16) >> 24) | o3;
		tmp[0][2] = octet;
		octet = ((mask3 << 24) >> 24) | o4;
		tmp[0][3] = octet;
	}
	return (4);
}

char	*put_uni_str(va_list **param)
{
	wchar_t			*str;
	char			*str2;
	char			*res;
	int				k;
	size_t			i;

	k = -1;
	i = 0;
	str = va_arg(**param, wchar_t *);
	if (str != NULL)
	{
		while (str[++k])
			i += sizeof(str[k]);
		str2 = ft_strnew(i);
		res = str2;
		while (*str != '\0')
		{
			k = put_uni_char((unsigned int)*str, &str2);
			str++;
			str2 = &str2[k];
		}
	}
	else
		res = ft_strdup("(null)");
	return (res);
}
