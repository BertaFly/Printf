/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:14:01 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 21:14:29 by inovykov         ###   ########.fr       */
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
	int				k;
	char			*tmp;

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
}

void	aply_precision(char **str, t_args *fl, int len)
{
	if ((S(fl->spec)) && (fl->prc < len || (WIPE_PRC)))
		aply_precision_str(str, fl);
	else
		aply_precision_nbr(str, fl, (int)ft_strlen(str[0]));
}
