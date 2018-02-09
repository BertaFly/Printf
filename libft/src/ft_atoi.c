/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:29:48 by inovykov          #+#    #+#             */
/*   Updated: 2017/10/30 14:29:53 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_is_space(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

static const char	*ft_find_end(const char *str)
{
	const char *s;

	while (*str == '0')
		str++;
	s = str;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			break ;
		s++;
	}
	return (s);
}

int					ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	const char			*tmp_str;
	const char			*end_digit;

	while (*str != '\0' && ft_is_space(*str))
		str++;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	end_digit = ft_find_end(str);
	res = 0;
	tmp_str = str - 1;
	while (++tmp_str < end_digit)
		res = res * 10LL + (unsigned long long)(*tmp_str - '0');
	if ((end_digit - str) > 19 || res >= 9223372036854775808uLL)
		return ((sign == 1) ? -1 : 0);
	return ((int)res * sign);
}
