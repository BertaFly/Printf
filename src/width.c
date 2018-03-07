/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:12:06 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 21:13:23 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	aply_width_symb(char **str, t_args *fl, int len)
{
	char			*tmp;
	int				i;

	i = -1;
	tmp = ft_strdup(*str);
	free(*str);
	if (*tmp == '\0' && fl->spec != 's' && fl->spec != 'S')
		*str = ft_strnew(--fl->width);
	else
		*str = ft_strnew(fl->width);
	if (fl->zero == '1' && fl->minus == '0')
		ft_memset((void*)*str, '0', (size_t)fl->width);
	else
		ft_memset((void*)*str, ' ', (size_t)fl->width);
	if (fl->minus == '1')
	{
		while (++i < len)
			str[0][i] = tmp[i];
	}
	else
	{
		while (--len > -1)
			str[0][--fl->width] = tmp[len];
	}
	free(tmp);
}

/*
*** Symbols in str align right
*/

void	aply_width_nbr_f_e(char *tmp, char **str, t_args *fl, int len)
{
	while (--len > -1 && tmp[len] != '-')
	{
		if ((tmp[len] == 'x' || tmp[len] == 'X') && fl->apl_fl0 == 1)
			break ;
		str[0][--fl->width] = tmp[len];
	}
	if (ft_atoi(tmp) < 0 && fl->apl_fl0 == 1 && !(U_NUM(fl->spec)))
		str[0][0] = '-';
	else if (ft_atoi(tmp) < 0 && fl->apl_fl0 == 0 && !(U_NUM(fl->spec)))
		str[0][--fl->width] = '-';
	if (fl->plus == '1' && fl->zero == '1' && ft_atoi(tmp) >= 0)
		str[0][0] = '+';
	else if (fl->plus == '1' && ft_atoi(tmp) > 0 && fl->space == '0')
		str[0][--fl->width] = '+';
	if (fl->plus == '0' && ft_atoi(tmp) >= 0 && fl->space == '1')
		str[0][0] = ' ';
	if ((SAVE_0X) && fl->apl_fl0 == 1)
		str[0][1] = (ft_strchr(tmp, 'X') == NULL ? 'x' : 'X');
}

void	aply_width_nbr(char **str, t_args *fl, int len)
{
	char			*tmp;
	int				i;
	int				k;

	i = -1;
	k = -1;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strnew(fl->width);
	if (fl->zero == '1' && fl->minus == '0' && fl->is_prc == 0)
		ft_memset((void*)*str, '0', (size_t)fl->width);
	else
		ft_memset((void*)*str, ' ', (size_t)fl->width);
	fl->apl_fl0 = (str[0][0] == '0' ? 1 : 0);
	if (fl->minus == '1')
	{
		if ((fl->plus == '1' || fl->space == '1') && ft_atoi(tmp) > 0)
			str[0][++i] = (fl->plus == '1' ? '+' : ' ');
		while (++k < len)
			str[0][++i] = tmp[k];
	}
	else
		aply_width_nbr_f_e(tmp, str, fl, len);
	free(tmp);
}

void	aply_width(char **tmp, t_args *fl, int len)
{
	if (!(IS_NUM(fl->spec)))
		aply_width_symb(tmp, fl, len);
	else
		aply_width_nbr(tmp, fl, len);
}
