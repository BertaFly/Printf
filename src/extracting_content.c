/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracting_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:05:56 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 22:30:17 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	extr_char(t_args *fl, va_list **param, char **tmp, int *z_chr)
{
	unsigned int	uni_char;

	if ((fl->spec == 'C' && MB_CUR_MAX == 1) || (SMAL_C))
	{
		tmp[0] = ft_strnew(1);
		tmp[0][0] = (char)va_arg(**param, int);
		*z_chr = (tmp[0][0] == 0 ? 1 : 0);
	}
	else if (fl->spec == 'C' || (fl->spec == 'c' && fl->size == 3))
	{
		tmp[0] = ft_strnew(4);
		uni_char = va_arg(**param, unsigned int);
		if (uni_char == 0)
		{
			*z_chr = 1;
			tmp[0][0] = 0;
		}
		else
			put_uni_char(uni_char, tmp);
	}
	else
	{
		tmp[0] = ft_strnew(1);
		tmp[0][0] = fl->hold;
	}
}

void	extr_arg(t_args *fl, va_list **param, char **tmp, int *z_chr)
{
	if ((C(fl->spec)) || fl->hold != '0')
		extr_char(fl, param, tmp, z_chr);
	else if (fl->spec == 's' || fl->spec == 'S')
	{
		if ((fl->spec == 'S' && MB_CUR_MAX == 1) || (SMAL_S))
		{
			tmp[0] = ft_strdup((char *)va_arg(**param, char*));
			if (tmp[0] == NULL)
				tmp[0] = ft_strdup("(null)");
		}
		else
			tmp[0] = put_uni_str(param);
	}
	else
		process_num(tmp, fl, param);
}
