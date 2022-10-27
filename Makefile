# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:24:20 by mfunyu            #+#    #+#              #
#    Updated: 2022/10/27 18:16:12 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

SRCS	:= ft_printf.c \
			ft_printf_utils.c \
			puts.c \
			puts2.c \
			sets.c \
			sets2.c
OBJS_DIR:= objs/
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
LIBFT	:= libft

.PHONY : all
all : $(NAME) $(LIBFT)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir $@

.PHONY : clean
clean :
	$(RM) -R $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT)

.PHONY : fclean
fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)

.PHONY : re
re : fclean all
