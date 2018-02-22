/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:49:21 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/22 15:44:15 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	ft_aply_size_un(t_args *flags, va_list *param)
{
	uintmax_t	nbr;
	
	// nbr = va_arg(*param, uintmax_t);
	// printf("%ju\n", nbr);
	if (flags->spec == 'O' || flags->spec == 'U')
	{
		nbr = va_arg(*param, unsigned long int);

		// nbr = (unsigned long int)nbr;
		return (nbr);
	}
	if (flags->size == '1' && flags->spec != 'p')
		nbr = (unsigned char)va_arg(*param, unsigned int);
		// nbr = (unsigned char)nbr;
	else if (flags->size == '2' && flags->spec != 'p')
		nbr = (unsigned short int)va_arg(*param, unsigned int);
		// nbr = (unsigned short int)nbr;
	else if (flags->size == '3' || flags->spec == 'p')
		nbr = va_arg(*param, unsigned long int);
		// nbr = (unsigned long int)nbr;
	else if (flags->size == '4' && flags->spec != 'p')
		nbr = va_arg(*param, unsigned long long int);
		// nbr = (unsigned long long int)nbr;
	else if (flags->size == '5' && flags->spec != 'p')
		nbr = va_arg(*param, uintmax_t);
		// nbr = (uintmax_t)nbr;
	else if (flags->size == '6' && flags->spec != 'p')
		nbr = va_arg(*param, uint64_t);
		// nbr = (uint64_t)nbr;
	else
	{
		nbr = va_arg(*param, unsigned int);

		// nbr = (unsigned int)nbr;
		// printf("I dont have size %ju\n", nbr);
	}
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

void		ft_process_num(char **tmp, t_args *flags, va_list **param)
{
	long long			nbr;
	unsigned long long	u_nbr;
	int					k;

	k = 0;
	nbr = 0;
	u_nbr = 0;
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
	if (flags->spec == 'o' || flags->spec == 'O')
		*tmp = ft_itoa_base(u_nbr, 8);
	if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p')
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
