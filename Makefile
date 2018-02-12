# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 13:16:28 by inovykov          #+#    #+#              #
#    Updated: 2018/02/12 15:51:31 by inovykov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

DIR_S = src

DIR_O = obj

HEADER = includes

SOURCES = ft_printf.c ft_itoa_base.c ft_itoa_un.c collect_parameters.c \
			process_num.c aply_param.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

.PHONY: all clean fclean re

all: obj $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp ./libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo libftprintf.a is ready

obj:
	@mkdir -p obj
	@echo Creating ft_printf object files

$(DIR_O)/%.o : $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf $(DIR_O)
	@echo A foulder with ft_printf object files was removed

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo libftprintf.a was removed

re: fclean all