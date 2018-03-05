/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:21:44 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/01 19:24:04 by inovykov         ###   ########.fr       */
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
# define S_10(x) x == 'd' || x == 'i' || x == 'D' || x == 'I'
# define U_10(x) x == 'u' || x == 'U'
# define U_8(x) x == 'o' || x == 'O'
# define U_16(x) x == 'x' || x == 'X'
# define P(x) x == 'p'
# define NOT_HASH (flags->spec != 'p' && flags->spec != 'o' && flags->spec != 'O' && flags->spec != 'x' && \
flags->spec != 'X') || (*str[0] == '0' && (flags->spec == 'o' || flags->spec == 'O'))

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
	int		is_precision;
	int		precision;
	char	size;
	char	spec;
	char	hold;
}				t_args;

char				*ft_itoa_un(unsigned long long nbr);
char				*ft_itoa_base(unsigned long long value, int base);
void				ft_put_struct(t_args *param);
void				ft_mem_flg(const char *format, t_args *flags);
int					ft_mem_size(const char *format, int i, t_args *flags);
int					ft_mem_digit(const char *format, int i, t_args *flags);
int					ft_parce_flags(const char *format, t_args *flags);
void				ft_process_num(char **tmp, t_args *flags, va_list **param);
void				ft_aply_precision_str(char **str, t_args *flags);
void				ft_aply_precision_nbr(char **str, t_args *flags);
void				ft_aply_hash_2(char *tmp, int len, char **str);
void				ft_aply_hash(char **str, t_args *flags);
int					ft_put_arg(t_args *flags, va_list **param);
void				ft_aply_width(char **str, t_args *flags);
void				ft_aply_width_not_nbr(char **str, t_args *flags);
void				ft_aply_hash(char **str, t_args *flags);
long long			ft_aply_size(t_args *flags, va_list *param);
uintmax_t			ft_aply_size_un(t_args *flags, va_list *param);
int					ft_printf_exten(const char *format, va_list *param);
int					ft_printf(const char *format, ...);

#endif
