# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 13:16:28 by inovykov          #+#    #+#              #
#    Updated: 2018/03/06 21:14:12 by inovykov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

DIR_S = src

HEADER = includes

SOURCES = ft_printf.c collect_parameters.c process_num.c aply_param.c \
			unicode.c extracting_content.c width.c precision.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(SOURCES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp ./libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a is ready"

%.o : $(DIR_S)/%.c
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJS)
	@echo "A foulder with ft_printf object files was removed"

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "libftprintf.a was removed"

re: fclean all