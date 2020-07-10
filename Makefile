# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:24:20 by mfunyu            #+#    #+#              #
#    Updated: 2020/07/10 20:07:01 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a
SRCS := ft_printf.c
OBJS := ${SRCS:%.c=%.o}

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT}
	ar rc ${OBJS}

clean :
	${RM} ${NAME}

fclean : clean
	${RM} ${OBJS}

re : fclean all

bonus :

.PHONY : all, clean, fclean, re, bonus
