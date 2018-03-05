/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:33:29 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/01 23:26:51 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <locale.h>
#include <limits.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// printf("%");
	// printf("{%S}\n", NULL);
	// ft_printf("{%S}\n", NULL);
// 	printf("NM %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
// 	ft_printf("MY %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
// %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	// ft_printf("%c", 0);
	// ft_printf("%C", 0);
	// printf("NM %hD, %hD\n", 0, USHRT_MAX);
	// ft_printf("MY %hD, %hD\n", 0, USHRT_MAX);
	// ft_printf("{%3C}", 0);
	// printf("{%+03d}", 0);
	// ft_printf("{%+03d}", 0);
	// printf("{% 03d}", 0);
	// ft_printf("{% 03d}", 0);
	// ft_printf("{%03.2d}", 0);
	// printf("%4.8x\n", 424242424);
	// printf("col bit = %i\n", ft_printf("%4.8x", 424242424));
	// printf("col bit = %i\n", printf("%4.8x", 424242424));
	// ft_printf("{%#.5x}", 1);
	ft_printf("{%#.5x}", 1);
	// printf("{%05.S}", L"42 c est cool");

	// printf("%.o, %.0O", 0, 0);
	// ft_printf("%.o, %.0O", 0, 0);

	// printf("%.i", 99);

	// printf("%c", 0);
	// ft_printf("%c", ' ');

//	char str[] = "this";
// ft_printf("%.0%\n");
// printf("%.0%\n");
  	// ft_printf("%   %\n", "test");
  	// printf("%   %\n", "test");

  	// ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
  	// printf("@moulitest: %#.x %#.0x\n", 0, 0);

  	// ft_printf("@moulitest: %s\n", NULL);
  	// printf("@moulitest: %s\n", NULL);
  	// ft_printf("len = %d\n", ft_printf("%C\n", 12215));
  	// printf("len = %d\n", printf("%C\n", 12215));

  	// ft_printf("%C\n", '🚭');
  	// ft_printf("my %10C\n", L'🙌');
  	// ft_printf("my %10C\n", L'😀');


  	//printf("nm %10lc\n", L'ф');
  	// printf("nm %5.0lc\n", L'¡');
// # 0177 (unsigned int)
  // ft_printf("%3u\n", 0);
  // printf("%3u", 0);
	// # 0179 (unsigned int)
  // ft_printf("%u\n", -1);
  // printf("%u", -1);


// # 0181 (unsigned int)
  // ft_printf("%u\n", 4294967296);
  // printf("%u", 4294967296);

//   1. (    0) --><--
//   2. (    1) -->0<--

// # 0183 (unsigned int)
  // ft_printf("%15u\n", 4294967295);
//   1. (   15) -->    -4294967295<--
//   2. (   15) -->     4294967295<--

// # 0185 (unsigned int)
//   ft_printf("%015u", 4294967295);
//   1. (   15) -->-00004294967295<--
//   2. (   15) -->000004294967295<--

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
