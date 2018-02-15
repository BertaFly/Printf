/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:33:29 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/13 16:50:56 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// ft_printf("%010x\n", 542);
	// ft_printf("%#x\n", 0);
	// ft_printf("%#08x\n", 42);
	// ft_printf("%#8x\n", 42);
	// printf("%#8x\n", 42);
	// ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	// printf("@moulitest: %.x %.0x\n", 0, 0);
	// ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	// printf("@moulitest: %5.x %5.0x\n", 0, 0);
	 // ft_printf("%.2x\n", 5427);
	 // printf("%.2x\n", 5427);
	// ft_printf("%5.2x", 5427);
	// printf("%5.2x", 5427);
	// ft_printf("@moulitest: %s\n", NULL);
	// printf("@moulitest: %s\n", NULL);
	// ft_printf("%.2c\n", NULL);
	// ft_printf("%.2c\n", 'a');
	// ft_printf("%s %s\n", NULL, "str");
	ft_printf("@moulitest: %c\n", 0);
	printf("@moulitest: %c", 0);

	// ft_printf("%s %s\n", NULL, "string");
	// printf("%s %s", NULL, "string");

	// printf("%.2c\n", NULL);
	// printf("%010x\n", 542);
	// ft_printf("hexedec con 0x %#x\n", 7561);
	// printf("hexedec con 0x %#x\n", 7561);
	
	// ft_printf("hexedec con 0x and prec %#.10x\n", 7561);
	// printf("hexedec con 0x and prec %#.10x\n", 7561);

	// ft_printf("octal %#o\n", 100);
	// printf("octal %#o\n", 100);
	
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
