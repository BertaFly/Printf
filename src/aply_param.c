/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aply_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:02:00 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/28 19:06:45 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		only_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	ft_aply_precision_str(char **str, t_args *flags)
{
	char	*tmp;
	int		k;

	// printf("*****I am aplying precision for str\n");
	// printf("precision = %d\n", flags->precision);
	tmp = ft_strdup(*str);
//	printf("tmp: %s\n", tmp);
	// size_t len = ft_strlen(tmp);
//	printf("len %zu\n", len);
//	printf("str: %s\n", *str);

	ft_memset((void*)*str, 0, ft_strlen(tmp));
	// printf("after bzero\n");
	k = -1;
	while (++k < flags->precision)
	{
		// printf("in a while\n");
		str[0][k] = tmp[k];
		// printf("str[0][%d] %c\n", k, str[0][k]);
	}
	// printf("->curently str is: %s<-\n", str[0]);
	free(tmp);
}

void	ft_aply_precision_nbr(char **str, t_args *flags)
{
	char	*tmp;
	size_t	len;
	int		k;
	
	k = flags->precision;
	len = ft_strlen(*str);
	if ((IS_NUM(flags->spec)) && ((int)len < flags->precision || ((int)len == flags->precision && ft_atoi(*str) < 0)))
	{
		// printf("SURPRIZE\n");
		tmp = ft_strdup(*str);
		free(*str);
		if (ft_atoi(tmp) < 0)
			k++;
		str[0] = ft_strnew(k);
		while (len > 0 && tmp[len - 1] != '-')
		{
			str[0][--k] = tmp[len - 1];
			len--;
		}
		while (--k >= 0)
			str[0][k] = '0';
		if (ft_atoi(tmp) < 0)
			str[0][0] = '-';
		free(tmp);
	}
	if ((IS_NUM(flags->spec)) && flags->is_precision == 1 && flags->precision == 0 && ft_atoi(*str) == 0)
		str[0][0] = '\0';
	// printf(">>>>>I am in ft_aply_precision_nbr\n");
	if (flags->spec == 's' && flags->precision < (int)len)
		ft_aply_precision_str(str, flags);
}

void	ft_aply_hash_2(char *tmp, int len, char **str)
{
	int		k;

	k = len + 1;
	*str = ft_strnew(k);
	// printf("aply hash 2\n");
	while (len >= 0)
	{
		str[0][k] = tmp[len];
		// printf("in str - %c\n", str[0][k]);
		len--;
		k--;
	}
	str[0][k] = '0';
	// printf("str full %s\n", str[0]);
}

void	ft_aply_hash(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		k;
	
	if (flags->hash == '0' || (NOT_HASH) || str[0][0] == '0' || (flags->spec != 'o' && str[0][0] == '\0'))
		return ;
	// else if (flags->spec == 'o' && flags->hash == '1' && flags->is_precision == 1 && str[0][0] == '\0')
	// 	return ;
	// printf("SURPRIZE!!! aplied hash\n");
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
	
	// printf("----aplying width-----\n");
	len = (int)ft_strlen(*str);
	i = -1;
	tmp = ft_strdup(*str);
	free(*str);
	// printf("flags->width bef %d\n", flags->width);
	if (*tmp == '\0' && flags->spec != 's')
		*str = ft_strnew(--flags->width);
	else
		*str = ft_strnew(flags->width);
	// printf("flags->width after %d\n", flags->width);

	// printf("flag->width %d\n", flags->width);
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
		// if (len != 0)
		{
			while (--len > -1)
			{
				str[0][--flags->width] = tmp[len];
				// len--;
			}
		}
		// else
		// {
		// 	while (flags->width > len)
		// 		str[0][--flags->width] = tmp[len--];
		// }
		// printf("str after aply width %s\n", res);
	}
	free(tmp);
}

void	ft_aply_width(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		i;
	int		k;
	int		exec_flg_0;
	
	// printf("aply WIDTH\n");

	len = (int)ft_strlen(*str);
	i = -1;
	k = -1;
	exec_flg_0 = 0;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strnew(flags->width);
	if (flags->zero == '1' && flags->minus == '0' && flags->is_precision == 0)
	{
		ft_memset((void*)*str, '0', (size_t)flags->width);
		exec_flg_0 = 1;
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
		{
			if ((tmp[len] == 'x' || tmp[len] == 'X') && flags->zero == '1' && flags->is_precision == 0)
				break ;
			str[0][--flags->width] = tmp[len];
		}
		if (ft_atoi(tmp) < 0 && exec_flg_0 == 1 && !(U_NUM(flags->spec)))
			str[0][0] = '-';
		else if (ft_atoi(tmp) < 0 && exec_flg_0 == 0 && !(U_NUM(flags->spec)))
		{
			// printf("tmp: %s\n", tmp);
			// printf("atoi returns %d\n", ft_atoi(tmp));
			str[0][--flags->width] = '-';
			// printf("SURPRIZE mathafaka\n");
		}
		if (flags->plus == '1' && flags->zero == '0' && ft_atoi(tmp) > 0 && flags->space == '0')
			str[0][--flags->width] = '+';
		if (flags->plus == '1' && flags->zero == '1' && ft_atoi(tmp) > 0)
			str[0][0] = '+';
		if (flags->plus == '0' && ft_atoi(tmp) > 0 && flags->space == '1')
			str[0][0] = ' ';
		if ((ft_strchr(tmp, 'x') != NULL || ft_strchr(tmp, 'X') != NULL) && flags->zero == '1' && flags->is_precision == 0)
		{
			if (ft_strchr(tmp, 'X') != NULL)
				str[0][1] = 'X';
			else
				str[0][1] = 'x';
		}
	}
	free(tmp);
}

unsigned int	ft_put_uni_char(unsigned int a, char **tmp)
{
	// unsigned int	new_a;
	// int	size = sizeof(a);
	unsigned char	octet;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	o3;
	unsigned char	o4;
	// unsigned int	mask0 = 0;
	unsigned int	mask1 = 49280;
	unsigned int	mask2 = 14712960;
	unsigned int	mask3 = 4034953344;


	if (a <= 127)
	{
		octet = a;
		tmp[0][0] = octet;
		// write(1, &octet, 1);
		return (1);
	}
	else if (a <= 2047)
	// else if (a <= 57279)
	{
		o2 = (a << 26) >> 26;
		o1 = ((a >> 6) << 27) >> 27;
		octet = (mask1 >> 8) | o1;
		tmp[0][0] = octet;
		// write(1, &octet, 1);
		octet = ((mask1 << 24) >> 24) | o2;
		tmp[0][1] = octet;
		// write(1, &octet, 1);
		return (2);
	}
	else if (a <= 65535)
	// else if (a <= 15712191)
	{
		o3 = (a << 26) >> 26;
		o2 = ((a >> 6) << 26) >> 26;
		o1 = ((a >> 12) << 28) >> 28;
		octet = (mask2 >> 16) | o1;
		tmp[0][0] = octet;
				// write(1, &octet, 1);
		octet = ((mask2<< 16) >> 24) | o2;
		tmp[0][1] = octet;

		// write(1, &octet, 1);
		octet = ((mask2 << 24) >> 24) | o3;
		tmp[0][2] = octet;
		return (3);
		// write(1, &octet, 1);
	}
	else
	{
		o4 = (a << 26) >> 26;
		o3 = ((a >> 6) << 26) >> 26;
		o2 = ((a >> 12) << 26) >> 26;
		o1 = ((a >> 18) << 29) >> 29;
		octet = (mask3 >> 24) | o1;
		tmp[0][0] = octet;

		// write(1, &octet, 1);
		octet = ((mask3 << 8) >> 24) | o2;
		tmp[0][1] = octet;

		// write(1, &octet, 1);
		octet = ((mask3 << 16) >> 24) | o3;
		tmp[0][2] = octet;

		// write(1, &octet, 1);
		octet = ((mask3 << 24) >> 24) | o4;
		tmp[0][3] = octet;

		// write(1, &octet, 1);
	}
	return (4);
	// return (new_a);
}

 char	*ft_put_uni_str(va_list **param)
{
	wchar_t *str;
	char *str2;
	unsigned int k = 0;

	int i = 0;
	str = va_arg(**param, wchar_t *);
	// str2 = ft_strnew((ft_strlen(str)) * 4);
	while (str[i])
		i++;
	str2 = ft_strnew(i);
	while (*str2)
	{
		k = ft_put_uni_char((unsigned int)*str, &str2);
		str = &str[k];
		str2 = &str2[k];
	}

	return (str2);
}

int	ft_put_arg(t_args *flags, va_list **param)
{
	int				len;
	char			*tmp;
	char			*tmp2;
	unsigned int	uni_char;

	tmp = NULL;
	len = 0;
	if (flags->spec == 'c' || flags->spec == 'C' || flags->spec == '0')
	{
		if (flags->spec != 'C' && (flags->spec == 'c' && flags->size != '3'))
		{
			tmp = ft_strnew(1);
			if (flags->spec == 'c')
			{
			// tmp[0] = (char)va_arg(**param, int);
				tmp[0] = (char)va_arg(**param, int);
				if (tmp[0] == 0)
				{
				// tmp = ft_strnew(1);
					tmp[0] = '\0';
				}
			}
		}
		else if (flags->spec == 'C' || (flags->spec == 'c' && flags->size == '3'))
		{
			tmp = ft_strnew(4);
			uni_char = va_arg(**param, unsigned int);
			ft_put_uni_char(uni_char, &tmp);
			// printf("len of tmp %zu\n", ft_strlen(tmp));
			// tmp[0] = ft_put_uni_char(uni_char);
		}
		else
			tmp[0] = flags->hold;
		// if (tmp[0] == (char)NULL)
		// {
		// 	// write(1, "\0", 1);
		// 	tmp[0] = '\0';
		// 	len = 1;
		// 	// return (len);
		// }
	}
	else if (flags->spec == 's' || flags->spec == 'S')
	{
		if (flags->spec != 'S' && (flags->spec == 's' && flags->size != '3'))
		{
		// printf("bef aloc mem\n");
		// tmp = ft_strnew(50);
		// tmp = ft_strdup((char *)va_arg(**param, char*));
			tmp = ft_strdup((char *)va_arg(**param, char*));
		// printf("after aloc mem\n");
			if (tmp == NULL)
			{
				tmp = ft_strnew(6);
				tmp = "(null)";
			}
		// tmp = ft_strdup((char *)va_arg(**param, char*));
		// tmp = (char *)va_arg(**param, char*);
		// if (tmp == NULL)
		// {
		// 	tmp = ft_strnew(6);
		// 	tmp = "(null)";
		// }
		}
		else
			tmp = ft_put_uni_str(param);
	}
	else
		ft_process_num(&tmp, flags, param);
	if (flags->is_precision == 1)
		ft_aply_precision_nbr(&tmp, flags);
	ft_aply_hash(&tmp, flags);
	if (flags->width > (int)ft_strlen(tmp))
	{
		if (!(IS_NUM(flags->spec)))
			ft_aply_width_not_nbr(&tmp, flags);
		else
			ft_aply_width(&tmp, flags);
	}
	else
	{
		if ((SIGNED_NUM(flags->spec)) && ft_atoi(tmp) >= 0)
		{
			if (flags->plus == '1')
			{
				// printf("TUT\n");
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
			if (flags->space == '1' && flags->plus == '0')
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
	if (only_space(tmp) && flags->spec == 'c')
	{
		write(1, tmp, (len + 1));
		return (len + 1);
	}
	else
		write(1, tmp, len);
	return (len);
}
