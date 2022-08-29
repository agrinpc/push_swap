# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:29:12 by miahmadi          #+#    #+#              #
#    Updated: 2022/08/29 23:49:21 by miahmadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
NAME_BONUS = checker.a
PROG = push_swap
PROG_BONUS = checker

LIBFT = ./libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =	push_swap \
		moves \
		moves_2 \
		fake_moves \
		fake_moves_2 \
		utils \
		utils_2 \
		utils_3 \
		a_utils \
		a_utils_1 \
		b_utils \
		b_utils_2 \
		b_utils_3 \
		b_utils_4 \
		b2_utils \
		free \
		do_1 \
		do_2 \
		common_utils \
		main \
		
FILES_B = moves_bonus \
			moves_bonus_2 \
			b_utils_2 \
			b_utils_3 \
			utils_2 \
			utils_3 \
			free \
			push_swap_bonus \
			bonus_main \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROG): $(NAME)
	$(CC) $(CFLAGS) -g $(NAME) -o $(PROG)

$(PROG_BONUS): $(NAME_BONUS)
	$(CC) $(CFLAGS) -g $(NAME_BONUS) -o $(PROG_BONUS)

$(NAME): libftmake $(OBJS)
	$(AR) $@ $(OBJS)

$(NAME_BONUS): libftmake_bonus $(OBJS_B)
	$(AR) $@ $(OBJS_B)

all: $(PROG)

bonus: $(PROG_BONUS)

libftmake:
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)

libftmake_bonus:
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	$(RM) $(PROG) $(NAME) $(PROG_BONUS) $(NAME_BONUS)
	@cd $(LIBFT) && $(MAKE) fclean

re: clean all

.PHONY: bonus all clean fclean re