# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 15:58:54 by tjung             #+#    #+#              #
#    Updated: 2021/07/16 22:46:27 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		 push_swap

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror

SRCS =		main.c tools.c \
			ft_memset.c ft_strlen.c ft_split.c ft_pw_atoi.c \
			ft_lst_add_back.c ft_lst_clear.c ft_lst_last.c ft_lst_new.c ft_lst_size.c \
			parsing.c parsing_tools.c argument_valid.c \
			func_push_a.c func_push_b.c func_reverse_rotate.c func_rotate.c func_swap.c \
			sort_ascending.c check_sorting.c calculation_tools.c sort_tools.c \
			sort_not_more_than_five.c sort_five_details.c \
			sort_more_than_five.c sort_more_five_details.c

OBJS =		$(SRCS:.c=.o)

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\033[0;33mCompiling..."
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "\033[0m"

clean:
	@echo "\n\033[0;31mCleaning..."
	rm -rf $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all