/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:10:21 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 22:21:36 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initial_masks(t_mask *mask)
{
	mask->uno = 49280;
	mask->dos = 14712960;
	mask->tres = 4034953344;
	mask->o1 = '0';
	mask->o2 = '0';
	mask->o3 = '0';
	mask->o4 = '0';
	mask->octet = '0';
}

/*
*** Record symbol up to 3 byte
*/

void	put_uni_char_upt3(unsigned int a, char **tmp, t_mask *mask)
{
	if (a <= 127)
		tmp[0][0] = a;
	else if (a <= 2047)
	{
		mask->o2 = (a << 26) >> 26;
		mask->o1 = ((a >> 6) << 27) >> 27;
		mask->octet = (mask->uno >> 8) | mask->o1;
		tmp[0][0] = mask->octet;
		mask->octet = ((mask->uno << 24) >> 24) | mask->o2;
		tmp[0][1] = mask->octet;
	}
	else
	{
		mask->o3 = (a << 26) >> 26;
		mask->o2 = ((a >> 6) << 26) >> 26;
		mask->o1 = ((a >> 12) << 28) >> 28;
		mask->octet = (mask->dos >> 16) | mask->o1;
		tmp[0][0] = mask->octet;
		mask->octet = ((mask->dos << 16) >> 24) | mask->o2;
		tmp[0][1] = mask->octet;
		mask->octet = ((mask->dos << 24) >> 24) | mask->o3;
		tmp[0][2] = mask->octet;
	}
}

void	put_uni_char_upt4(unsigned int a, char **tmp, t_mask *mask)
{
	mask->o4 = (a << 26) >> 26;
	mask->o3 = ((a >> 6) << 26) >> 26;
	mask->o2 = ((a >> 12) << 26) >> 26;
	mask->o1 = ((a >> 18) << 29) >> 29;
	mask->octet = (mask->tres >> 24) | mask->o1;
	tmp[0][0] = mask->octet;
	mask->octet = ((mask->tres << 8) >> 24) | mask->o2;
	tmp[0][1] = mask->octet;
	mask->octet = ((mask->tres << 16) >> 24) | mask->o3;
	tmp[0][2] = mask->octet;
	mask->octet = ((mask->tres << 24) >> 24) | mask->o4;
	tmp[0][3] = mask->octet;
}

int		put_uni_char(unsigned int a, char **tmp)
{
	t_mask	mask;

	initial_masks(&mask);
	if (a <= 127)
	{
		put_uni_char_upt3(a, tmp, &mask);
		return (1);
	}
	else if (a <= 2047)
	{
		put_uni_char_upt3(a, tmp, &mask);
		return (2);
	}
	else if (a <= 65535)
	{
		put_uni_char_upt3(a, tmp, &mask);
		return (3);
	}
	else
		put_uni_char_upt4(a, tmp, &mask);
	return (4);
}

char	*put_uni_str(va_list **param)
{
	wchar_t	*str;
	char	*str2;
	char	*res;
	int		k;
	size_t	i;

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
