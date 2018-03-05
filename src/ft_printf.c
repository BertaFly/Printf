/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:53:10 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/05 21:31:50 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_exten(const char *format, va_list *param)
{
	t_args	fl;
	int		i;
	int		j;
	int		count;
	int		len;
	int		res;

	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		count = 0;
		res = 0;
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i++], 1);
			count++;
		}
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				write(1, &format[i], 1);
				i = i + 2;
				count++;
			}
			else
			{
				if (format[++i] == '\0')
					break ;
				put_struct(&fl);
				j = parce_flg(&format[i], &fl);
				res = put_arg(&fl, &param);
				i = i + j;
			}
		}
		if (fl.spec == 'S' && fl.is_prc != 0 && res == 0 && count == 0)
			len = -1;
		else
			len = len + count + res;
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
