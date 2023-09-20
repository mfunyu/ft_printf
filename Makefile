# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:24:20 by mfunyu            #+#    #+#              #
#    Updated: 2023/09/20 14:52:15 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                    SOURCES                                   #
# ---------------------------------------------------------------------------- #

SRCS	:= ft_printf.c \
			num_converters.c \
			puts.c \
			puts_helpers.c \
			set_formats.c \
			set_flags.c

# ---------------------------------------------------------------------------- #
#                                     PATHS                                    #
# ---------------------------------------------------------------------------- #

DIR_OBJS:= objs
OBJS_DIR:= objs/
LIBFT	:= libft
VPATH	:= srcs

# ---------------------------------------------------------------------------- #
#                                   VARIABLES                                  #
# ---------------------------------------------------------------------------- #

NAME	:= libftprintf.a
CC		:= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
INCLUDES:= -I $(LIBFT) -I includes -I .

# ---------------------------------------------------------------------------- #
#                                  BASIC RULES                                 #
# ---------------------------------------------------------------------------- #

.PHONY : all
all : $(NAME) $(LIBFT)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

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

.PHONY : bonus
bonus: all
