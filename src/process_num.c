/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:49:21 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/05 15:46:51 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	ft_aply_size_un(t_args *flags, va_list *param)
{
	uintmax_t	nbr;
	
	nbr = va_arg(*param, uintmax_t);
	// printf("%ju\n", nbr);
	// if (flags->spec == 'O' || flags->spec == 'U')
	// {
	// 	nbr = va_arg(*param, unsigned long int);
	// 	// printf("%li\n", nbr);
	// 	// nbr = (unsigned long int)nbr;
	// 	return (nbr);
	// }
	if (flags->size == '1' && flags->spec != 'p' && flags->spec != 'O' && flags->spec != 'U')
	// if (flags->size == '1' && flags->spec != 'p')
		// nbr = (unsigned char)va_arg(*param, unsigned int);
		nbr = (unsigned char)nbr;
	// else if (flags->size == '2' && flags->spec != 'p')
	else if (flags->size == '2' && flags->spec != 'p' && flags->spec != 'O' && flags->spec != 'U')
		// nbr = (unsigned short int)va_arg(*param, unsigned int);
		nbr = (unsigned short int)nbr;
	// else if (flags->size == '3' || flags->spec == 'p')
	else if ((flags->size == '3' || flags->spec == 'p') && flags->spec != 'O' && flags->spec != 'U')
		// nbr = va_arg(*param, unsigned long int);
		nbr = (unsigned long int)nbr;
	// else if (flags->size == '4' && flags->spec != 'p')
	else if (flags->size == '4' && flags->spec != 'p' && flags->spec != 'O' && flags->spec != 'U')
		// nbr = va_arg(*param, unsigned long long int);
		nbr = (unsigned long long int)nbr;
	// else if (flags->size == '5' && flags->spec != 'p')
	else if (flags->size == '5' && flags->spec != 'p' && flags->spec != 'O' && flags->spec != 'U')
		// nbr = va_arg(*param, uintmax_t);
		nbr = (uintmax_t)nbr;
	// else if (flags->size == '6' && flags->spec != 'p')
	else if (flags->size == '6' && flags->spec != 'p' && flags->spec != 'O' && flags->spec != 'U')
		// nbr = va_arg(*param, uint64_t);
		nbr = (uint64_t)nbr;
	else if (flags->size == '0' && flags->spec != 'p' && flags->spec != 'O' && flags->spec != 'U')
	// else
	{
		// nbr = va_arg(*param, unsigned int);

		nbr = (unsigned int)nbr;
		// printf("I dont have size %ju\n", nbr);
	}
	else if ((flags->spec == 'O' || flags->spec == 'U') && (flags->size == '1' || flags->size == '2'))
		nbr = (long int)nbr;
	return (nbr);
}

long long	ft_aply_size(t_args *flags, va_list *param)
{
	intmax_t	nbr;
	
	nbr = va_arg(*param, intmax_t);
	// printf("early nbr %jd\n", nbr);

	// if (flags->spec == 'D' || flags->spec == 'I')
		// nbr = va_arg(*param, long int);
	// else if (flags->size == '1')
	if (flags->size == '1' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (signed char)nbr;
		// nbr = (signed char)va_arg(*param, int);
	else if (flags->size == '2' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (short int)nbr;
		// nbr = (short int)va_arg(*param, int);
	else if (flags->size == '3' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (long int)nbr;
		// nbr = (long int)va_arg(*param, int);
	else if (flags->size == '4' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (long long int)nbr;
		// nbr = (long long int)va_arg(*param, int);
	else if (flags->size == '5' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (intmax_t)nbr;
		// nbr = (intmax_t)va_arg(*param, int);
	else if (flags->size == '6' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (ssize_t)nbr;
		// nbr = (ssize_t)va_arg(*param, int);
	else if (flags->size == '0' && flags->spec != 'D' && flags->spec != 'I')
		nbr = (int)nbr;
	else if (flags->spec == 'D' && (flags->size == '1' || flags->size == '2'))
	{
	// else if (flags->spec == 'D' && (flags->size == '1'))
		nbr = (unsigned int)nbr;
		// printf("later nbr %jd\n", nbr);

	// printf("nbr %jd\n", nbr);
	}
	return (nbr);
}

void		ft_process_num(char **tmp, t_args *flags, va_list **param)
{
	long long			nbr;
	unsigned long long	u_nbr;
	int					k;

	k = 0;
	nbr = 0;
	u_nbr = 0;
	// if (U_NUM(flags->spec))
	if (U_NUM(flags->spec))
		u_nbr = ft_aply_size_un(flags, &**param);
	else
		nbr = ft_aply_size(flags, &**param);
	if (flags->spec == 'i' || flags->spec == 'd' || flags->spec == 'D' || flags->spec == 'u' || flags->spec == 'U')
	{
		if (flags->spec == 'i' || flags->spec == 'd' || flags->spec == 'D')
			*tmp = ft_itoa(nbr);
		else
		{
			// printf("u_nbr just in cacse %llu\n", u_nbr);
			*tmp = ft_itoa_un(u_nbr);
			// printf("passed u_nbr to str %s\n", *tmp);
		}
	}
	else if (flags->spec == 'o' || flags->spec == 'O')
	{
		*tmp = ft_itoa_base(u_nbr, 8);
		// printf("tmp: %s>\n", tmp[0]);
	}
	else if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
	{
		*tmp = ft_itoa_base(u_nbr, 16);
		if (flags->spec == 'X')
		{
			while (tmp[0][k])
			{
				tmp[0][k] = ft_toupper(tmp[0][k]);
				k++;
			}
		}
	}
}
