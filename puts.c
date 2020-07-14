/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 12:58:30 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_cnt(char c, int *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}

void	ft_putstr_cnt(char *s, int *cnt)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_cnt(*s++, cnt);
}

void	ft_putpadding(char c, int n, int *cnt)
{
	while(n-- > 0)
		ft_putchar_cnt(c, cnt);
}

int		ft_putchr(int t_int, t_flag *flag, int *cnt)
{
	if (flag->min_width && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->min_width - 1, cnt);
	ft_putchar_cnt((char)t_int, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', flag->min_width - 1, cnt);
	return (0);
}

int		ft_putstr(char *t_str, int len, t_flag *flag, int p, int *cnt)
{
	if (flag->min_width && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->min_width - len, cnt);
	if (p)
	{
		ft_putstr_cnt("0x", cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', flag->min_width - len, cnt);
	// printf("zero : %d\n", flag->zero_padding);
	// printf("left : %d\n", flag->left_justified);
	// printf("min : %d\n\n", flag->min_width);
	return (0);
}

int		ft_putstr2(char *t_str, int len, t_flag *flag, int *cnt)
{
	if (flag->min_width && !flag->left_justified && !flag->zero_padding)
	{
		ft_putpadding(' ', (flag->precision > len ? flag->min_width - flag->precision : flag->min_width - len), cnt);
	}
	if (flag->precision > 0 || flag->zero_padding)
	{
		if (*t_str == '-')
		{
			ft_putchar_cnt('-', cnt);
			flag->precision++;
			t_str++;
		}
		ft_putpadding('0', (flag->precision  > 0 ? flag->precision - len : flag->min_width - len), cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', (flag->precision > len ? flag->min_width - flag->precision : flag->min_width - len), cnt);
	return (0);
}

void		write_c(va_list *ap, t_flag *flag, int *cnt)
{
	int				t_int;

	t_int = va_arg(*ap, int);
	if (flag->min_width && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->min_width - 1, cnt);
	ft_putchar_cnt((char)t_int, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', flag->min_width - 1, cnt);
}

void		write_s(va_list *ap, t_flag *flag, int *cnt)
{
	char			*t_str;

	t_str = va_arg(*ap, char *);
	if (!t_str)
		t_str = "(null)";
		// t_str = (t_str ? t_str : "(null)");
	else if (flag->precision >= 0 && flag->precision < (int)ft_strlen(t_str))
	{
		t_str = ft_substr(t_str, 0, flag->precision);
	}
	ft_putstr(t_str, ft_strlen(t_str), flag, 0, cnt);
}

