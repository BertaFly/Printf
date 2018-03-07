/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aply_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:02:00 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 21:18:37 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	aply_hash_2(char *tmp, int len, char **str)
{
	int				k;

	k = len + 1;
	*str = ft_strnew(k);
	while (len >= 0)
	{
		str[0][k] = tmp[len];
		len--;
		k--;
	}
	str[0][k] = '0';
}

void	aply_hash(char **str, t_args *fl)
{
	char			*tmp;
	int				len;
	int				k;

	if ((fl->hash == '0' || (NOT_HASH) || (HASH_X0) || \
		(fl->spec == 'x' && (WIPE_PRC))) && !(P(fl->spec)))
		return ;
	tmp = ft_strdup(*str);
	len = (int)ft_strlen(*str);
	free(*str);
	if (fl->spec == 'o' || fl->spec == 'O')
		aply_hash_2(tmp, len, str);
	if (fl->spec == 'x' || fl->spec == 'X' || fl->spec == 'p')
	{
		k = len + 2;
		*str = ft_strnew(k);
		while (--len > -1)
			str[0][--k] = tmp[len];
		if (fl->spec == 'X')
			str[0][1] = 'X';
		else
			str[0][1] = 'x';
		str[0][0] = '0';
	}
	free(tmp);
}

/*
*** Puts space or + where it needed according to flgs
*/

void	aply_flg(t_args *fl, char **tmp, int len)
{
	char			*tmp2;

	if ((S_10(fl->spec)) && ft_atoi(tmp[0]) >= 0)
	{
		if (fl->plus == '1' || fl->space == '1')
		{
			tmp2 = ft_strdup(tmp[0]);
			free(tmp[0]);
			len = ft_strlen(tmp2);
			tmp[0] = ft_strnew(len + 1);
			if (fl->space == '1' && fl->plus == '0')
				ft_memset(tmp[0], 32, (len + 1));
			while (len > 0)
			{
				tmp[0][len] = tmp2[len - 1];
				len--;
			}
			if (fl->plus == '1')
				tmp[0][len] = '+';
			free(tmp2);
		}
	}
}
