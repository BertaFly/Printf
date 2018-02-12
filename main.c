/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:33:29 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/12 20:48:24 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_put_arg(t_args *flags, va_list **param)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	if (flags->spec == 'c' || flags->spec == '0')
	{
		tmp = ft_strnew(1);
		if (flags->spec == 'c')
			tmp[0] = (char)va_arg(**param, int);
		else
			tmp[0] = flags->hold;
	}
	else if (flags->spec == 's')
		tmp = ft_strdup(va_arg(**param, char *));
	else
		ft_process_num(&tmp, flags, param);
	if (flags->is_precigion == 1)
		ft_aply_precigion_nbr(&tmp, flags);
	ft_aply_hash(&tmp, flags);
	if (flags->width > (int)ft_strlen(tmp))
	{
		if (!(IS_NUM(flags->spec)))
			ft_aply_width_not_nbr(&tmp, flags);
		else
			ft_aply_width(&tmp, flags);
	}
	len = (int)ft_strlen(tmp);
	write(1, tmp, len);
	return (len);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// ft_printf("hexedec con 0x %#x\n", 7561);
	// printf("hexedec con 0x %#x\n", 7561);
	
	// ft_printf("hexedec con 0x and prec %#.10x\n", 7561);
	// printf("hexedec con 0x and prec %#.10x\n", 7561);

	ft_printf("octal %#o\n", 100);
	printf("octal %#o\n", 100);
	
	// ft_printf("hexedec con 0x and prec %#010.0x\n", 7561);
	// printf("hexedec con 0x and prec %#010.0x\n", 7561);

	// ft_printf("digit %hhd\n", -2147483648);
	// ft_printf("digit %hho\n", -2147483648);
	// ft_printf("digit %hd\n", -2147483648);
	// ft_printf("digit %ho\n", -2147483648);
	// int res = ft_printf("digit %-20.5d\n", 7);
	// printf("res %d\n", res);
	// ft_printf("char %c\n", 'x');
	// ft_printf("without %05.2mama\n", "str");
	// printf("without %05.2mama\n", "str");
	// ft_printf("str %-10.1s\n", "one");
	// ft_printf("digit %-20.5d\n", 7);
	// ft_printf("digit %lo\n", -2147483648);
	// printf("digit %ld\n", -1);
	// printf("digit %lo\n", -2147483648);
}
