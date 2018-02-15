/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aply_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:02:00 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/13 16:51:16 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	if ((IS_NUM(flags->spec)) && (int)len < flags->precision)
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
	while (--len > -1)
		str[0][--k] = tmp[len];
	str[0][--k] = '0';
}

void	ft_aply_hash(char **str, t_args *flags)
{
	char	*tmp;
	int		len;
	int		k;
	
	if ((NOT_HASH) || ft_atoi(*str) == 0)
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
	
	// printf("----aplying width-----\n");
	len = (int)ft_strlen(*str);
	i = -1;
	tmp = ft_strdup(*str);
	*str = ft_strnew(flags->width);
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
		while (--len > -1)
			str[0][--flags->width] = tmp[len];

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
	
	len = (int)ft_strlen(*str);
	i = -1;
	k = -1;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strnew(flags->width);
	if (flags->zero == '1' && flags->minus == '0' && flags->is_precision == 0)
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
		{
			if ((tmp[len] == 'x' || tmp[len] == 'X') && flags->zero == '1' && flags->is_precision == 0)
				break ;
			str[0][--flags->width] = tmp[len];
		}
		if (ft_atoi(tmp) < 0)
			str[0][0] = '-';
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

int	ft_put_arg(t_args *flags, va_list **param)
{
	int		len;
	char	*tmp;
//    char    *res;

	tmp = NULL;
	if (flags->spec == 'c' || flags->spec == '0')
	{
		tmp = ft_strnew(1);
		if (flags->spec == 'c')
			tmp[0] = (char)va_arg(**param, int);
		else
			tmp[0] = flags->hold;
		if (tmp[0] == (char)NULL)
		{
			write(1, "\0", 1);
			// tmp[0] = '\0';
			len = 1;
			return (len);
		}
	}
	else if (flags->spec == 's')
	{
		// printf("       spec is str\n");
		tmp = ft_strdup((char *)va_arg(**param, char*));
		// tmp = (char *)va_arg(**param, char*);
		if (tmp == NULL)
		{
			tmp = ft_strnew(6);
			tmp = "(null)";
		}
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
	len = (int)ft_strlen(tmp);
	write(1, tmp, len);
	return (len);
}
