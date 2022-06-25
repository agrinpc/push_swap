# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:29:12 by miahmadi          #+#    #+#              #
#    Updated: 2022/06/14 16:47:04 by miahmadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
PROG = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = push_swap \
		moves \
		utils \
		main \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROG): $(NAME)
	$(CC) $(CFLAGS) -g $(NAME) -o $(PROG)

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(PROG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PROG) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re