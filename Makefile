# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:24:20 by mfunyu            #+#    #+#              #
#    Updated: 2022/10/27 17:46:56 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a
SRCS := ft_printf.c ft_printf_utils.c puts.c puts2.c sets.c sets2.c
OBJS := $(SRCS:%.c=%.o)
LIBFT := ./libft

all : $(NAME) $(LIBFT)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean :
	$(RM) $(NAME) $(OBJS)
	$(MAKE) fclean -C $(LIBFT)

re : fclean all

bonus:

.PHONY : all, clean, fclean, re, bonus
