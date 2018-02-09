/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:53:10 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/09 17:30:20 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_exten(const char *format, va_list *param)
{
	t_args	flags;
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
		while(format[i] != '%' && format[i] != '\0')
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
				ft_put_struct(&flags);
				i++;
				j = ft_parce_flags(&format[i], &flags);
				res = ft_put_arg(&flags, &param);
				i = i + j;
			}
		}
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
		return((int)write(1, format, ft_strlen(format)));
	va_start(param, format);
	len = ft_printf_exten(format, &param);
	va_end(param);
	return(len);
}
