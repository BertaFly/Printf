/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:53:10 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/01 15:27:03 by inovykov         ###   ########.fr       */
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
		// printf("at the begining of printf\n");
		count = 0;
		res = 0;
		while(format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i++], 1);
			count++;
			// printf("put everything exepf after %%\n");
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
				ft_put_struct(&flags);
				// i++;
				// printf("bef parce\n");
				j = ft_parce_flags(&format[i], &flags);
				// printf("after parce\n");
				res = ft_put_arg(&flags, &param);
				// printf("apperently I use all parameters %%\n");
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
