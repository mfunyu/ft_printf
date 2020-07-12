/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:45:21 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/12 11:51:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
#include <stdio.h>

typedef struct	s_flag
{
	int			left_justified;
	int			right_justified;
	int			justified;
	int			precision;
	int			zero_padding;
	int			digits;

}				t_flag;

int		ft_printf(const char *format, ...);
char	*itohex(unsigned int nb, int X);

/* puts */
int		ft_putchr(int t_int, t_flag *flag);
int		ft_putstr(char *t_str, int len, t_flag *flag, int p);

#endif
