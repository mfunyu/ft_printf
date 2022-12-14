/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:45:21 by mfunyu            #+#    #+#             */
/*   Updated: 2022/10/27 21:23:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_flag
{
	char		format;
	int			left_justified;
	int			zero_padding;
	int			min_width;
	int			precision;

}				t_flag;

int				ft_printf(const char *format, ...);

/*
** puts.c
*/

void			ft_putchar_cnt(char c, int *cnt);
void			ft_putstr_cnt(char *s, int *cnt);
void			ft_putstr_cnt_limit(char *s, int len, int *cnt);
void			ft_putpadding(char c, int n, int *cnt);
int				ft_putnumstr(char *t_str, int len, t_flag *flag, int *cnt);
int				ft_puthexstr(char *t_str, int len, t_flag *flag, int *cnt);
void			put_c(va_list *ap, t_flag *flag, int *cnt);
void			put_s(va_list *ap, t_flag *flag, int *cnt);

/*
** sets.c
*/

int				set_di(va_list *ap, t_flag *flag, int *cnt);
int				set_u(va_list *ap, t_flag *flag, int *cnt);
int				set_p(va_list *ap, t_flag *flag, int *cnt);
int				set_hex(va_list *ap, t_flag *flag, int *cnt);
void			set_precision(const char **str, va_list *ap, t_flag *flag);
void			set_min_width(const char **str, va_list *ap, t_flag *flag);

/*
** ft_prninf_utils.c
*/

unsigned int	get_digits(long long nb, unsigned int base);
void			ft_utohex(char *strhex, size_t nb, int upper);
void			ft_uitoa(char *nb, unsigned int n);
void			ft_itoa_stack(char *nb, int n);
int				max(int a, int b);

#endif
