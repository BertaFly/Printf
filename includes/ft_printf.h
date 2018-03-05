/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:21:44 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/05 21:28:02 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define FLG(x) x == '+' || x == '-' || x == '0' || x == ' ' || x == '#'
# define SIZE(x) x == 'h' || x == 'l' || x == 'j' || x == 'z'
# define S_10(x) x == 'd' || x == 'i' || x == 'D' || x == 'I'
# define U_8(x) x == 'o' || x == 'O'
# define U_10(x) x == 'u' || x == 'U'
# define U_16(x) x == 'x' || x == 'X'
# define P(x) x == 'p'
# define S(x) x == 's' || x == 'S'
# define C(x) x == 'c' || x == 'C'
# define U_NUM(x) (U_10(x)) || (U_16(x)) || (U_8(x)) || (P(x))
# define IS_NUM(x) (U_NUM(x)) || (S_10(x))
# define SPECS(x)  (S(x)) || C(x) || (IS_NUM(x))
# define ERROR(x) !(IS_NUM(x)) || !(SIZE(x)) || !(FLG(x))
# define WIPE_PRC (fl->is_prc == 1 && fl->prc == 0)
# define HASH_X0 (str[0][0] == '0' && fl->is_prc == 0)
# define SAVE_0X (ft_strchr(tmp, 'x') != NULL || ft_strchr(tmp, 'X') != NULL)
# define NOT_HASH ((fl->spec != 'o' && fl->spec != 'O' && fl->spec != 'x' && \
fl->spec != 'X') || (*str[0] == '0' && (fl->spec == 'o' || fl->spec == 'O')))
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_args
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
	int		width;
	int		is_prc;
	int		prc;
	char	size;
	char	spec;
	char	hold;
}					t_args;

char				*ft_itoa_un(unsigned long long nbr);
char				*ft_itoa_base(unsigned long long value, int base);
void				put_struct(t_args *param);
void				mem_flg(const char *format, t_args *fl);
int					mem_size(const char *format, int i, t_args *fl);
int					mem_digit(const char *format, int i, t_args *fl);
int					parce_flg(const char *format, t_args *fl);
void				process_num(char **tmp, t_args *fl, va_list **param);
void				aply_precision_str(char **str, t_args *fl);
void				aply_precision_nbr(char **str, t_args *fl, int len);
void				aply_hash_2(char *tmp, int len, char **str);
void				aply_hash(char **str, t_args *fl);
int					put_arg(t_args *fl, va_list **param);
void				aply_width(char **str, t_args *fl);
void				aply_width_not_nbr(char **str, t_args *fl, int len);
void				aply_hash(char **str, t_args *fl);
long long			aply_size(t_args *fl, va_list *param);
uintmax_t			aply_size_un(t_args *fl, va_list *param);
int					ft_printf_exten(const char *format, va_list *param);
int					ft_printf(const char *format, ...);

#endif
