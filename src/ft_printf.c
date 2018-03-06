/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:53:10 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 19:51:15 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_struct(t_args *param)
{
	param->minus = '0';
	param->plus = '0';
	param->space = '0';
	param->hash = '0';
	param->zero = '0';
	param->width = 0;
	param->is_prc = 0;
	param->prc = 0;
	param->size = 0;
	param->spec = '0';
	param->hold = '0';
	param->apl_fl0 = 0;
}

int		do_magic(const char **format, va_list *param, t_args *fl)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (format[0][i + 1] == '%')
	{
		write(1, &format[0][++i], 1);
		i++;
		res++;
		format[0] = &format[0][i];
	}
	else
	{
		if (format[0][i++] != '\0')
		{
			put_struct(fl);
			i = parce_flg(&format[0][i], fl);
			res = put_arg(fl, &param);
		}
		format[0] = &format[0][i + 1];
	}
	return (res);
}

int		ft_printf_exten(const char *format, va_list *param)
{
	t_args	fl;
	int		count;
	int		len;
	int		res;

	len = 0;
	while (*format != '\0')
	{
		count = 0;
		res = 0;
		while (*format != '%' && *format != '\0')
		{
			write(1, format, 1);
			format++;
			count++;
		}
		if (*format == '%')
			res = do_magic(&format, param, &fl);
		len = ((RET_ER) ? -1 : (len + count + res));
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	param;
	int		len;

	len = 0;
	if (format == NULL)
		return (-1);
	if (ft_strchr(format, '%') == 0)
		return ((int)write(1, format, ft_strlen(format)));
	va_start(param, format);
	len = ft_printf_exten(format, &param);
	va_end(param);
	return (len);
}
