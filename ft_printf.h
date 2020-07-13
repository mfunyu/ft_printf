/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:45:21 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/13 20:44:55 by mfunyu           ###   ########.fr       */
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
int		ft_putchr(int t_int, t_flag *flag, int *cnt);
int		ft_putstr(char *t_str, int len, t_flag *flag, int p, int *cnt);
int		ft_putstr2(char *t_str, int len, t_flag *flag, int *cnt);
char		*ft_uitoa(unsigned int n);

#endif
