/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aply_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:02:00 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/12 20:48:37 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_aply_precigion_str(char **str, t_args *flags)
{
	char	*tmp;
	int		k;

	tmp = ft_strdup(*str);
	ft_bzero(*str, ft_strlen(tmp));
	k = -1;
	while (++k < flags->precigion)
		str[0][k] = tmp[k];
	free(tmp);
}

void	ft_aply_precigion_nbr(char **str, t_args *flags)
{
	char	*tmp;
	size_t	len;
	int		k;
	
	k = flags->precigion;
	len = ft_strlen(*str);
	if ((IS_NUM(flags->spec)) && (int)len < flags->precigion)
	{
		tmp = ft_strdup(*str);
		free(*str);
		str[0] = ft_strnew(k);
		while (len > 0)
		{
			str[0][--k] = tmp[len - 1];
			len--;
		}
		while (--k >= 0)
			str[0][k] = '0';
		free(tmp);
	}
	if (flags->spec == 's' && flags->precigion < (int)len)
		ft_aply_precigion_str(str, flags);
}

void	ft_aply_hash_2(char *tmp, int len, char **str)
{
	int		k;

	k = len + 1;
	*str = ft_strnew(k);
	while (--len > -1)
		str[0][--k] = tmp[len];
	str[0][--k] = '0';
}

void	ft_aply_hash(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		k;
	
	if (NOT_HASH)
		return ;
	tmp = ft_strdup(*str);
	len = (int)ft_strlen(*str);
	free(*str);
	if (flags->spec == 'o' || flags->spec == 'O')
		ft_aply_hash_2(tmp, len, str);
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
	free(tmp);
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
	if (flags->zero == '1' && flags->minus == '0' && flags->is_precigion == '0')
		ft_memset((void*)*str, '0', (size_t)flags->width);
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
