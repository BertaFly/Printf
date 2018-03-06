/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:49:21 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 20:45:03 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	aply_size_un(t_args *fl, va_list *param)
{
	uintmax_t	nbr;

	nbr = va_arg(*param, uintmax_t);
	if (fl->size == 1 && fl->spec != 'p' && fl->spec != 'O' && fl->spec != 'U')
		nbr = (unsigned char)nbr;
	else if (fl->size == 2 && fl->spec != 'p' && fl->spec != 'O' && fl->spec != 'U')
		nbr = (unsigned short int)nbr;
	else if ((fl->size == 3 || fl->spec == 'p') && fl->spec != 'O' && fl->spec != 'U')
		nbr = (unsigned long int)nbr;
	else if (fl->size == 4 && fl->spec != 'p' && fl->spec != 'O' && fl->spec != 'U')
		nbr = (unsigned long long int)nbr;
	else if (fl->size == 5 && fl->spec != 'p' && fl->spec != 'O' && fl->spec != 'U')
		nbr = (uintmax_t)nbr;
	else if (fl->size == 6 && fl->spec != 'p' && fl->spec != 'O' && fl->spec != 'U')
		nbr = (uint64_t)nbr;
	else if (fl->size == 0 && fl->spec != 'p' && fl->spec != 'O' && fl->spec != 'U')
		nbr = (unsigned int)nbr;
	else if ((fl->spec == 'O' || fl->spec == 'U') && (fl->size == 1 || fl->size == 2))
		nbr = (long int)nbr;
	return (nbr);
}

long long	aply_size(t_args *fl, va_list *param)
{
	intmax_t	nbr;

	nbr = va_arg(*param, intmax_t);
	if (fl->size == 1 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (signed char)nbr;
	else if (fl->size == 2 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (short int)nbr;
	else if (fl->size == 3 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (long int)nbr;
	else if (fl->size == 4 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (long long int)nbr;
	else if (fl->size == 5 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (intmax_t)nbr;
	else if (fl->size == 6 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (ssize_t)nbr;
	else if (fl->size == 0 && fl->spec != 'D' && fl->spec != 'I')
		nbr = (int)nbr;
	else if (fl->spec == 'D' && (fl->size == 1 || fl->size == 2))
		nbr = (unsigned int)nbr;
	return (nbr);
}

void		process_num(char **tmp, t_args *fl, va_list **param)
{
	long long			nbr;
	unsigned long long	u_nbr;
	int					k;

	k = 0;
	nbr = 0;
	u_nbr = 0;
	if (U_NUM(fl->spec))
		u_nbr = aply_size_un(fl, &**param);
	else
		nbr = aply_size(fl, &**param);
	if ((S_10(fl->spec)) || (U_10(fl->spec)))
	{
		if (S_10(fl->spec))
			*tmp = ft_itoa(nbr);
		else
			*tmp = ft_itoa_un(u_nbr);
	}
	else if (fl->spec == 'o' || fl->spec == 'O')
		*tmp = ft_itoa_base(u_nbr, 8);
	else if ((U_16(fl->spec)) || fl->spec == 'p')
	{
		*tmp = ft_itoa_base(u_nbr, 16);
		if (fl->spec == 'X')
		{
			while (tmp[0][k])
			{
				tmp[0][k] = ft_toupper(tmp[0][k]);
				k++;
			}
		}
	}
}
