/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:21:44 by inovykov          #+#    #+#             */
/*   Updated: 2018/02/09 17:49:28 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define SPECS(x) x == 's' || x == 'S' || x == 'c' || x == 'C' || \
x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' || \
x == 'u' || x == 'U' || x == 'x' || x == 'X'
# define FLG(x) x == '+' || x == '-' || x == '0' || x == ' ' || x == '#'
# define SIZE(x) x == 'h' || x == 'l' || x == 'j' || x == 'z' 
# define ERROR(x) x != 's' && x != 'S' && x != 'c' && x != 'C' && \
x != 'p' && x != 'd' && x != 'D' && x != 'i' && x != 'o' && x != 'O' && \
x != 'u' && x != 'U' && x != 'x' && x != 'X' && x != '.' && \
x != '+' && x != '-' && x != '0' && x != ' ' && x != '#' && \
x != 'h' && x != 'l' && x != 'j' && x != 'z'
# define IS_NUM(x) x == 'p' || x == 'd' || x == 'D' || x == 'i' || \
x == 'o' || x == 'O' || x == 'u' || x == 'U' || x == 'x' || x == 'X'
# define U_NUM(x) x == 'o' || x == 'O' || x == 'x' || x == 'X' || \
x == 'u' || x == 'U' || x == 'p'

#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

typedef struct	s_args
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
	char	star;
	int		width;
	int		is_precigion;
	int		precigion;
	char	size;
	char	spec;
	char	hold;
}				t_args;

char				*ft_itoa_un(unsigned long long nbr);
char				*ft_itoa_base(unsigned long long value, int base);
void				ft_put_struct(t_args *param);
void				ft_mem_flg(const char *format, t_args *flags);
int					ft_mem_size(const char *format, int i, t_args *flags);
int					ft_parce_flags(const char *format, t_args *flags);
int					ft_put_arg(t_args *flags, va_list **param);
void				ft_aply_width(char **str, t_args *flags);
void				ft_aply_width_not_nbr(char **str, t_args *flags);
void				ft_aply_hash(char **str, t_args *flags);
void				ft_aply_precigion(char **str, t_args *flags);
long long			ft_aply_size(t_args *flags, va_list *param);
uintmax_t			ft_aply_size_un(t_args *flags, va_list *param);
int					ft_printf_exten(const char *format, va_list *param);
int					ft_printf(const char *format, ...);

#endif
