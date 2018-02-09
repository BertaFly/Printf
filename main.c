/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:33:29 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/09 17:58:43 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

uintmax_t	ft_aply_size_un(t_args *flags, va_list *param)
{
	uintmax_t	nbr;
	
	nbr = va_arg(*param, uintmax_t);
	if (flags->spec == 'O' || flags->spec == 'U')
	{
		nbr = (unsigned long int)nbr;
		return (nbr);
	}
	if (flags->size == '1' && flags->spec != 'p')
		nbr = (unsigned char)nbr;
	else if (flags->size == '2' && flags->spec != 'p')
		nbr = (unsigned short int)nbr;
	else if (flags->size == '3' || flags->spec == 'p')
		nbr = (unsigned long int)nbr;
	else if (flags->size == '4' && flags->spec != 'p')
		nbr = (unsigned long long int)nbr;
	else if (flags->size == '5' && flags->spec != 'p')
		nbr = (uintmax_t)nbr;
	else if (flags->size == '6' && flags->spec != 'p')
		nbr = (uint64_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

long long	ft_aply_size(t_args *flags, va_list *param)
{
	intmax_t	nbr;
	
	nbr = va_arg(*param, intmax_t);
	if (flags->size == '1')
		nbr = (signed char)nbr;
	else if (flags->size == '2')
		nbr = (short int)nbr;
	else if (flags->size == '3' || flags->spec == 'D')
		nbr = (long int)nbr;
	else if (flags->size == '4')
		nbr = (long long int)nbr;
	else if (flags->size == '5')
		nbr = (intmax_t)nbr;
	else if (flags->size == '6')
		nbr = (ssize_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

void	ft_aply_precigion(char **str, t_args *flags)
{
	char	*tmp;
	size_t	len;
	int		i;
	int		mark;
	int		k;
	
	mark = 0;
	k = flags->precigion;
	len = ft_strlen(*str);
	// printf("\nHERE1\n len  %d\n", (int)len);
	// printf("\nHERE2\n prec %d\n", flags->precigion);
	if ((IS_NUM(flags->spec)) && (int)len < flags->precigion)
	{
		tmp = ft_strdup(*str);
		free(*str);
		str[0] = ft_strnew(k);
		// ft_memset((void*)*str, '0', flags->precigion);
		// printf("len %zu\n", len);
		while (len > 0)
		{
			// if (tmp[len] == 'x' || tmp[len] == 'X')
			// {
			// 	printf("find x \n");
			// 	mark = 1;
			// 	break ;
			// }
			str[0][--k] = tmp[len - 1];
			len--;
			// k--;
			// printf("str %c\n", str[0][k+1]);
			// printf("tmp %c\n", tmp[len]);
		}
		while (--k >= 0)
			str[0][k] = '0';
		if (mark == 1)
		{
			str[0][1] = tmp[len]; // adding x or X
			str[0][0] = '0';
		}
		free(tmp);
	}
	if (flags->spec == 's' && flags->precigion < (int)len)
	{
		tmp = ft_strdup(*str);
		ft_bzero(*str, ft_strlen(tmp));
		//		*str = ft_strnew(flags->precigion);
		//		printf("\n presig = %d\n", flags->precigion);
		//		printf("in tmp: %s\n", tmp);
		i = 0;
		//		*str = ft_strnew(3);
		//		*str = malloc(sizeof(char) * 3);
		//		*str[0] = '0';
		//		tmp[1] = '1';
		//		printf("in tmp: %s\n", tmp);
		
		//		printf("len of str %zu\n", ft_strlen(*str));
		//		*str[1] = '1';
		//		*str[2] = '\0';
		
		//		printf("in str: %s\n", *str);
		//		printf("len of str %zu\n", ft_strlen(*str));
		//		printf("str before: %s\n", *str);
		//		printf("second char in str %c\n", str[0][1]);
		while (i < flags->precigion)
		{
			
			//			printf("pointer to char in str %p\n", *str+i);
			//			printf("i = %d\n", i);
			//			printf("current char tmp %c\n", tmp[i]);
			//			printf("current char str %c\n", *str[i]);
			str[0][i] = tmp[i];
			i++;
			//			printf("str in while: %s\n", *str);
			
		}
		free(tmp);
	}
}

void	ft_aply_hash(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		k;
	
	if (flags->hash == '0' || *str[0] == '0' || (flags->spec != 'p' && flags->spec != 'o' && flags->spec != 'O' && flags->spec != 'x' && flags->spec != 'X'))
		return ;
	tmp = ft_strdup(*str);
	len = (int)ft_strlen(*str);
	free(*str);
	if (flags->spec == 'o' || flags->spec == 'O')
	{
		k = len + 1;
		*str = ft_strnew(k);
		while (--len > -1)
			str[0][--k] = tmp[len];
		str[0][--k] = '0';
	}
	if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
	{
		k = len + 2;
		*str = ft_strnew(k);
		while (--len > -1)
			str[0][--k] = tmp[len];
		if (flags->spec == 'X')
			str[0][1] = 'X';
		else
			str[0][1] = 'x';
		str[0][0] = '0';
	}
}

void	ft_aply_width_not_nbr(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		i;
	
	len = (int)ft_strlen(*str);
	i = -1;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strnew(flags->width);
	if (flags->zero == '1' && flags->minus == '0')
		ft_memset((void*)*str, '0', (size_t)flags->width);
	else
		ft_memset((void*)*str, ' ', (size_t)flags->width);
	if (flags->minus == '1')
	{
		while (++i < len)
			str[0][i] = tmp[i];
	}
	else
	{
		while (--len > -1)
			str[0][--flags->width] = tmp[len];
	}
	free(tmp);
}

void	ft_aply_width(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		i;
	int		k;
	
	len = (int)ft_strlen(*str);
	i = -1;
	k = -1;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strnew(flags->width);
	 // printf("flags->minus %c\n", flags->minus);
	 // 	printf("flags->plus %c\n", flags->plus);
	 // 	printf("flags->zero %c\n", flags->zero);
	 // 	printf("flags->space %c\n", flags->space);
	if (flags->zero == '1' && flags->minus == '0')
	{
		ft_memset((void*)*str, '0', (size_t)flags->width);
		// printf("TUT\n");
	}
	else
		ft_memset((void*)*str, ' ', (size_t)flags->width);
	if (flags->minus == '1')
	{
		if (flags->plus == '1' && ft_atoi(tmp) > 0)
			str[0][++i] = '+';
		if (flags->plus == '0' && flags->space == '1' && ft_atoi(tmp) > 0)
			str[0][++i] = ' ';
		while (++k < len)
			str[0][++i] = tmp[k];
	}
	else
	{
		while (--len > -1 && tmp[len] != '-')
			str[0][--flags->width] = tmp[len];
		if (ft_atoi(tmp) < 0)
			str[0][0] = '-';
		if (flags->plus == '1' && flags->zero == '0' && ft_atoi(tmp) > 0 && flags->space == '0')
			str[0][--flags->width] = '+';
		if (flags->plus == '1' && flags->zero == '1' && ft_atoi(tmp) > 0)
			str[0][0] = '+';
		if (flags->plus == '0' && ft_atoi(tmp) > 0 && flags->space == '1')
			str[0][0] = ' ';
	}
	free(tmp);
}

int	ft_put_arg(t_args *flags, va_list **param)
{
	int len;
	long long nbr;
	unsigned long long u_nbr;
	int k;
	char	*tmp = NULL;
	
	k = 0;
	nbr = 0;
	u_nbr = 0;
	if (flags->spec == 'c')
	{
		tmp = ft_strnew(1);
		tmp[0] = (char)va_arg(**param, int);
	}
	else if (flags->spec == 's')
		tmp = ft_strdup(va_arg(**param, char *));
	else if (IS_NUM(flags->spec))
	{
		if (U_NUM(flags->spec))
			u_nbr = ft_aply_size_un(flags, &**param);
		else
			nbr = ft_aply_size(flags, &**param);
		if (flags->spec == 'i' || flags->spec == 'd' || flags->spec == 'D' || flags->spec == 'u' || flags->spec == 'U')
		{
			if (flags->spec == 'i' || flags->spec == 'd' || flags->spec == 'D')
				tmp = ft_itoa(nbr);
			else
				tmp = ft_itoa_un(u_nbr);
		}
		if (flags->spec == 'o' || flags->spec == 'O')
			tmp = ft_itoa_base(u_nbr, 8);
		if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
		{
			tmp = ft_itoa_base(u_nbr, 16);
			if (flags->spec == 'X')
			{
				while (tmp[k])
				{
					tmp[k] = ft_toupper(tmp[k]);
					k++;
				}
			}
		}
	}
	else
	{
		tmp = ft_strnew(1);
		tmp[0] = flags->hold;
	}
	if (flags->is_precigion == 1)
		ft_aply_precigion(&tmp, flags);
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
	// ft_printf("digit %hhd\n", -2147483648);
	// ft_printf("digit %hho\n", -2147483648);
	// ft_printf("digit %hd\n", -2147483648);
	// ft_printf("digit %ho\n", -2147483648);
	int res = ft_printf("digit %-20d\n", 7);
	printf("res %d\n", res);
	// ft_printf("digit %lo\n", -2147483648);
	// printf("digit %ld\n", -1);
	// printf("digit %lo\n", -2147483648);
}
