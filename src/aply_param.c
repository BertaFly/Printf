/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aply_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:02:00 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/05 21:43:27 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	aply_precision_str(char **str, t_args *fl)
{
	char			*tmp;
	int				k;

	tmp = ft_strdup(*str);
	ft_memset((void*)*str, 0, ft_strlen(tmp));
	k = -1;
	while (++k < fl->prc)
		str[0][k] = tmp[k];
	free(tmp);
}

void	aply_precision_nbr(char **str, t_args *fl, int len)
{
	char			*tmp;
	int				k;

	k = fl->prc;
	if ((IS_NUM(fl->spec)) && len <= fl->prc)
	{
		tmp = ft_strdup(*str);
		free(*str);
		ft_atoi(tmp) < 0 ? k++ : k;
		str[0] = ft_strnew(k);
		ft_memset(str[0], '0', (size_t)k);
		while (len > 0 && tmp[len - 1] != '-')
		{
			str[0][--k] = tmp[len - 1];
			len--;
		}
		if (ft_atoi(tmp) < 0)
			str[0][0] = '-';
		free(tmp);
	}
	if ((IS_NUM(fl->spec)) && (WIPE_PRC) && ft_atoi(*str) == 0)
		str[0][0] = '\0';
	if ((S(fl->spec)) && (fl->prc < len || (WIPE_PRC)))
		aply_precision_str(str, fl);
}

void	aply_hash_2(char *tmp, int len, char **str)
{
	int				k;

	k = len + 1;
	*str = ft_strnew(k);
	while (len >= 0)
	{
		str[0][k] = tmp[len];
		len--;
		k--;
	}
	str[0][k] = '0';
}

void	aply_hash(char **str, t_args *fl)
{
	char			*tmp;
	int				len;
	int				k;

	if ((fl->hash == '0' || (NOT_HASH) || (HASH_X0) || \
		(fl->spec == 'x' && (WIPE_PRC))) && !(P(fl->spec)))
		return ;
	tmp = ft_strdup(*str);
	len = (int)ft_strlen(*str);
	free(*str);
	if (fl->spec == 'o' || fl->spec == 'O')
		aply_hash_2(tmp, len, str);
	if (fl->spec == 'x' || fl->spec == 'X' || fl->spec == 'p')
	{
		k = len + 2;
		*str = ft_strnew(k);
		while (--len > -1)
			str[0][--k] = tmp[len];
		if (fl->spec == 'X')
			str[0][1] = 'X';
		else
			str[0][1] = 'x';
		str[0][0] = '0';
	}
	free(tmp);
}

void	aply_width_not_nbr(char **str, t_args *fl, int len)
{
	char			*tmp;
	int				i;

	i = -1;
	tmp = ft_strdup(*str);
	free(*str);
	if (*tmp == '\0' && fl->spec != 's' && fl->spec != 'S')
		*str = ft_strnew(--fl->width);
	else
		*str = ft_strnew(fl->width);
	if (fl->zero == '1' && fl->minus == '0')
		ft_memset((void*)*str, '0', (size_t)fl->width);
	else
		ft_memset((void*)*str, ' ', (size_t)fl->width);
	if (fl->minus == '1')
	{
		while (++i < len)
			str[0][i] = tmp[i];
	}
	else
	{
		while (--len > -1)
			str[0][--fl->width] = tmp[len];
	}
	free(tmp);
}

void	aply_width(char **str, t_args *fl)
{
	char			*tmp;
	int				len;
	int				i;
	int				k;
	int				apl_fl0;

	len = (int)ft_strlen(*str);
	i = -1;
	k = -1;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strnew(fl->width);
	if (fl->zero == '1' && fl->minus == '0' && fl->is_prc == 0)
		ft_memset((void*)*str, '0', (size_t)fl->width);
	else
		ft_memset((void*)*str, ' ', (size_t)fl->width);
	apl_fl0 = (str[0][0] == '0' ? 1 : 0);
	if (fl->minus == '1')
	{
		if (fl->plus == '1' && ft_atoi(tmp) > 0)
			str[0][++i] = '+';
		else if (fl->space == '1' && ft_atoi(tmp) > 0)
			str[0][++i] = ' ';
		while (++k < len)
			str[0][++i] = tmp[k];
	}
	else
	{
		while (--len > -1 && tmp[len] != '-')
		{
			if ((tmp[len] == 'x' || tmp[len] == 'X') && apl_fl0 == 1)
				break ;
			str[0][--fl->width] = tmp[len];
		}
		if (ft_atoi(tmp) < 0 && apl_fl0 == 1 && !(U_NUM(fl->spec)))
			str[0][0] = '-';
		else if (ft_atoi(tmp) < 0 && apl_fl0 == 0 && !(U_NUM(fl->spec)))
			str[0][--fl->width] = '-';
		if (fl->plus == '1' && fl->zero == '1' && ft_atoi(tmp) >= 0)
			str[0][0] = '+';
		else if (fl->plus == '1' && ft_atoi(tmp) > 0 && fl->space == '0')
			str[0][--fl->width] = '+';
		if (fl->plus == '0' && ft_atoi(tmp) >= 0 && fl->space == '1')
			str[0][0] = ' ';
		if ((SAVE_0X) && apl_fl0 == 1)
			str[0][1] = (ft_strchr(tmp, 'X') == NULL ? 'x' : 'X');
	}
	free(tmp);
}

int		put_uni_char(unsigned int a, char **tmp)
{
	unsigned char	octet;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	o3;
	unsigned char	o4;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	if (a <= 127)
	{
		octet = a;
		tmp[0][0] = octet;
		return (1);
	}
	else if (a <= 2047)
	{
		o2 = (a << 26) >> 26;
		o1 = ((a >> 6) << 27) >> 27;
		octet = (mask1 >> 8) | o1;
		tmp[0][0] = octet;
		octet = ((mask1 << 24) >> 24) | o2;
		tmp[0][1] = octet;
		return (2);
	}
	else if (a <= 65535)
	{
		o3 = (a << 26) >> 26;
		o2 = ((a >> 6) << 26) >> 26;
		o1 = ((a >> 12) << 28) >> 28;
		octet = (mask2 >> 16) | o1;
		tmp[0][0] = octet;
		octet = ((mask2 << 16) >> 24) | o2;
		tmp[0][1] = octet;
		octet = ((mask2 << 24) >> 24) | o3;
		tmp[0][2] = octet;
		return (3);
	}
	else
	{
		o4 = (a << 26) >> 26;
		o3 = ((a >> 6) << 26) >> 26;
		o2 = ((a >> 12) << 26) >> 26;
		o1 = ((a >> 18) << 29) >> 29;
		octet = (mask3 >> 24) | o1;
		tmp[0][0] = octet;
		octet = ((mask3 << 8) >> 24) | o2;
		tmp[0][1] = octet;
		octet = ((mask3 << 16) >> 24) | o3;
		tmp[0][2] = octet;
		octet = ((mask3 << 24) >> 24) | o4;
		tmp[0][3] = octet;
	}
	return (4);
}

char	*put_uni_str(va_list **param)
{
	wchar_t			*str;
	char			*str2;
	char			*res;
	int				k;
	size_t			i;

	k = -1;
	i = 0;
	str = va_arg(**param, wchar_t *);
	if (str != NULL)
	{
		while (str[++k])
			i += sizeof(str[k]);
		str2 = ft_strnew(i);
		res = str2;
		while (*str != '\0')
		{
			k = put_uni_char((unsigned int)*str, &str2);
			str++;
			str2 = &str2[k];
		}
	}
	else
		res = ft_strdup("(null)");
	return (res);
}

int		put_arg(t_args *fl, va_list **param)
{
	int				len;
	char			*tmp;
	char			*tmp2;
	unsigned int	uni_char;
	int				zero_char;

	tmp = NULL;
	len = 0;
	zero_char = 0;
	if (fl->spec == 'c' || fl->spec == 'C' || fl->spec == '0')
	{
		if ((fl->spec == 'C' && MB_CUR_MAX == 1) || (fl->spec == 'c' && fl->size != '3'))
		{
			tmp = ft_strnew(1);
			tmp[0] = (char)va_arg(**param, int);
			if (tmp[0] == 0)
				zero_char = 1;
		}
		else if (fl->spec == 'C' || (fl->spec == 'c' && fl->size == '3'))
		{
			tmp = ft_strnew(4);
			uni_char = va_arg(**param, unsigned int);
			if (uni_char == 0)
			{
				zero_char = 1;
				tmp[0] = 0;
			}
			else
				put_uni_char(uni_char, &tmp);
		}
		else
		{
			tmp = ft_strnew(1);
			tmp[0] = fl->hold;
		}
	}
	else if (fl->spec == 's' || fl->spec == 'S')
	{
		if ((fl->spec == 'S' && MB_CUR_MAX == 1) || (fl->spec == 's' && fl->size != '3'))
		{
			tmp = ft_strdup((char *)va_arg(**param, char*));
			if (tmp == NULL)
				tmp = ft_strdup("(null)");
		}
		else
			tmp = put_uni_str(param);
	}
	else
		process_num(&tmp, fl, param);
	if (fl->is_prc == 1)
		aply_precision_nbr(&tmp, fl, (int)ft_strlen(tmp));
	aply_hash(&tmp, fl);
	if (fl->width > (int)ft_strlen(tmp))
	{
		if (!(IS_NUM(fl->spec)))
			aply_width_not_nbr(&tmp, fl, (int)ft_strlen(tmp));
		else
			aply_width(&tmp, fl);
	}
	else
	{
		if ((S_10(fl->spec)) && ft_atoi(tmp) >= 0)
		{
			if (fl->plus == '1')
			{
				tmp2 = ft_strdup(tmp);
				free(tmp);
				len = ft_strlen(tmp2);
				tmp = ft_strnew(len + 1);
				while (len > 0)
				{
					tmp[len] = tmp2[len - 1];
					len--;
				}
				tmp[len] = '+';
				free(tmp2);
			}
			if (fl->space == '1' && fl->plus == '0')
			{
				tmp2 = ft_strdup(tmp);
				free(tmp);
				len = ft_strlen(tmp2);
				tmp = ft_strnew(len + 1);
				ft_memset(tmp, 32, (len + 1));
				while (len > 0)
				{
					tmp[len] = tmp2[len - 1];
					len--;
				}
				free(tmp2);
			}
		}
	}
	len = (int)ft_strlen(tmp);
	if (zero_char == 1)
		len = len + 1;
	write(1, tmp, len);
	free(tmp);
	return (len);
}
