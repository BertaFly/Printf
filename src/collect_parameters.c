/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:36:16 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 21:18:50 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void		mem_flg(const char *format, t_args *fl)
{
	if (*format == '+')
		fl->plus = '1';
	if (*format == '-')
		fl->minus = '1';
	if (*format == ' ')
		fl->space = '1';
	if (*format == '0')
		fl->zero = '1';
	if (*format == '#')
		fl->hash = '1';
}

int			mem_size(const char *format, int i, t_args *fl)
{
	if (format[i] == 'h' && format[i + 1] == 'h' && fl->size < 1)
	{
		i++;
		fl->size = 1;
	}
	else if (format[i] == 'h' && format[i + 1] != 'h' && fl->size < 2)
		fl->size = 2;
	else if (format[i] == 'l' && format[i + 1] != 'l' && fl->size < 3)
		fl->size = 3;
	else if (format[i] == 'l' && format[i + 1] == 'l' && fl->size < 4)
	{
		i++;
		fl->size = 4;
	}
	else if (format[i] == 'j' && fl->size < 5)
		fl->size = 5;
	else if (format[i] == 'z' && fl->size < 6)
		fl->size = 6;
	return (i);
}

int			mem_digit(const char *format, int i, t_args *fl)
{
	if (*format == '.')
	{
		fl->prc = ft_atoi(&format[1]);
		fl->is_prc = 1;
		i = i + ft_len(fl->prc);
	}
	else
	{
		fl->width = ft_atoi(format);
		i = i + ft_len(fl->width) - 1;
	}
	return (i);
}

int			parce_flg(const char *format, t_args *fl)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (FLG(format[i]))
			mem_flg(&format[i], fl);
		else if (ft_isdigit(format[i]) || format[i] == '.')
			i = mem_digit(&format[i], i, fl);
		else if (SIZE(format[i]))
			i = mem_size(format, i, fl);
		else if (SPECS(format[i]))
		{
			fl->spec = format[i++];
			break ;
		}
		else if ((ERROR(format[i])) && ft_isdigit(format[i]) == 0)
		{
			fl->hold = format[i++];
			break ;
		}
		i++;
	}
	return (i);
}
