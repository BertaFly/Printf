# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 15:56:20 by inovykov          #+#    #+#              #
#    Updated: 2018/02/07 11:49:14 by inovykov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

DIR_S = src

DIR_O = obj

HEADER = includes

SOURCES =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_sqrt.c \
		ft_swap.c \
		ft_list_size.c \
		ft_factorial.c \
		ft_is_space.c \
		ft_itoa_un.c ft_itoa_base.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re

all: obj $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft.a is ready"

obj:
	@mkdir -p obj
	@echo "Creating libft object files"

$(DIR_O)/%.o : $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(DIR_O)
	@echo "A foulder with libft object files was removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "libft.a was removed"

re: fclean all
