/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:45:21 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 15:35:20 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct	s_flag
{
	char		format;
	int			left_justified;
	int			zero_padding;
	int			min_width;
	int			precision;

}				t_flag;

int		ft_printf(const char *format, ...);
char	*itohex(unsigned int nb, int X);

/* puts */
int		ft_putchr(int t_int, t_flag *flag, int *cnt);
int		ft_putstr(char *t_str, int len, t_flag *flag, int p, int *cnt);
int		ft_putstr2(char *t_str, int len, t_flag *flag, int *cnt);
char		*ft_uitoa(unsigned int n);
void	ft_putstr_cnt(char *s, int *cnt);
void	ft_putchar_cnt(char c, int *cnt);
unsigned int	get_digits(long long nb, unsigned int base);
char		*ft_itoa2(int n);

void		write_c(va_list *ap, t_flag *flag, int *cnt);
void		write_s(va_list *ap, t_flag *flag, int *cnt);
void		set_di(va_list *ap, t_flag *flag, int *cnt);
void		set_u(va_list *ap, t_flag *flag, int *cnt);
void		set_hex(va_list *ap, t_flag *flag, int *cnt);
void		set_precision(const char **str, va_list *ap, t_flag *flag);
void		set_min_width(const char **str,va_list *ap, t_flag *flag);
#endif
