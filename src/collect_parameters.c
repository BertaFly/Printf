/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_parameters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:36:16 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/09 18:00:05 by inovykov         ###   ########.fr       */
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

void		ft_put_struct(t_args *param)
{
	param->minus = '0';
	param->plus = '0';
	param->space = '0';
	param->hash = '0';
	param->zero = '0';
	param->star = '0';
	param->width = 0;
	param->is_precigion = 0;
	param->precigion = 0;
	param->size = '0';
	param->spec = '0';
	param->hold = '0';
}

void		ft_mem_flg(const char *format, t_args *flags)
{
	if (*format == '+')
		flags->plus = '1';
	if (*format == '-')
		flags->minus = '1';
	if (*format == ' ')
		flags->space = '1';
	if (*format == '0')
		flags->zero = '1';
	if (*format == '#')
		flags->hash = '1';
}

int			ft_mem_size(const char *format, int i, t_args *flags)
{
	if (format[i] == 'h' && format[i + 1] == 'h')
	{
		i++;
		flags->size = '1';
	}
	else if (format[i] == 'h')
		flags->size = '2';
	else if (format[i] == 'l' && format[i + 1] != 'l')
		flags->size = '3';
	else if (format[i] == 'l' && format[i + 1] == 'l')
	{
		i++;
		flags->size = '4';
	}
	else if (format[i] == 'j')
		flags->size = '5';
	else
		flags->size = '6';
	return (i);
}

int			ft_parce_flags(const char *format, t_args *flags)
{
	int	i;
	
	i = 0;
	while (format[i] != '\0')
	{
		if (FLG(format[i]))
			ft_mem_flg(&format[i], flags);
		else if (ft_isdigit(format[i]))
		{
			flags->width = ft_atoi(&format[i]);
			i = i + ft_len(flags->width) - 1;
		}
		else if (format[i] == '.')
		{
			flags->precigion = ft_atoi(&format[i + 1]);
			flags->is_precigion = 1;
			i = i + ft_len(flags->precigion);
		}
		else if (SIZE(format[i]))
			i = ft_mem_size(format, i, flags);
		else if (SPECS(format[i]))
		{
			flags->spec = format[i];
			i++;
			break ;
		}
		else if (ERROR(format[i]) && ft_isdigit(format[i]) == 0)
		{
			flags->hold = format[i];
			i++;
			break ;
		}
		i++;
	}
	return (i);
}
