/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:21:44 by inovykov          #+#    #+#             */
/*   Updated: 2018/03/06 22:49:35 by inovykov         ###   ########.fr       */
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
# define NOT_HASH ((!(U_8(fl->spec)) && !(U_16(fl->spec))) || (N_HASH2))
# define N_HASH2 (*str[0] == '0' && (U_8(fl->spec)))
# define RET_ER (fl.spec == 'S' && fl.is_prc != 0 && res == 0 && count == 0)
# define SMAL_S (fl->spec == 's' && fl->size != 3)
# define SMAL_C (fl->spec == 'c' && fl->size != 3)
# define NO_NU (fl->spec != 'O' && fl->spec != 'U')
# define O_U (fl->spec == 'O' || fl->spec == 'U')
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_args
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
	int		width;
	int		is_prc;
	int		prc;
	int		size;
	char	spec;
	char	hold;
	int		apl_fl0;
}				t_args;

typedef struct	s_mask
{
	unsigned int	uno;
	unsigned int	dos;
	unsigned int	tres;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	unsigned char	octet;
}				t_mask;

char			*ft_itoa_un(unsigned long long nbr);
char			*ft_itoa_base(unsigned long long value, int base);
void			put_struct(t_args *param);
void			mem_flg(const char *format, t_args *fl);

/*
*** file_name.c
*/

int				mem_size(const char *format, int i, t_args *fl);
int				mem_digit(const char *format, int i, t_args *fl);
int				parce_flg(const char *format, t_args *fl);
void			process_num(char **tmp, t_args *fl, va_list **param);
int				put_uni_char(unsigned int a, char **tmp);
void			extr_char(t_args *fl, va_list **param, char **tmp, int *z_chr);
void			extr_arg(t_args *fl, va_list **param, char **tmp, int *z_chr);
char			*put_uni_str(va_list **param);
void			aply_precision(char **str, t_args *fl, int len);
void			aply_precision_str(char **str, t_args *fl);
void			aply_precision_nbr(char **str, t_args *fl, int len);
void			aply_hash_2(char *tmp, int len, char **str);
void			aply_hash(char **str, t_args *fl);
void			aply_flg(t_args *fl, char **tmp, int len);
int				put_arg(t_args *fl, va_list **param);
void			aply_width(char **str, t_args *fl, int len);
void			aply_width_nbr(char **str, t_args *fl, int len);
void			aply_width_symb(char **str, t_args *fl, int len);
void			aply_hash(char **str, t_args *fl);
long long		aply_size(t_args *fl, va_list *param);
uintmax_t		aply_size_un(t_args *fl, va_list *param);
int				ft_printf_exten(const char *format, va_list *param);
int				ft_printf(const char *format, ...);

#endif
