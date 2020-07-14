/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 19:44:41 by mfunyu           ###   ########.fr       */
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

int		ft_putstr(char *t_str, int len, t_flag *flag, int *cnt)
{
	// 	printf("zero : %d\n", flag->zero_padding);
	// printf("left : %d\n", flag->left_justified);
	// printf("min : %d\n\n", flag->min_width);
	// printf("min : %d\n\n", flag->precision);
	if (flag->min_width && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->min_width - len, cnt);
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', flag->min_width - len, cnt);
	return (0);
}

/*
** [     -000007] instead of [     00000-7]
*/

int		ft_putnumstr(char *t_str, int len, t_flag *flag, int p, int *cnt)
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
			t_str++;
		}
		ft_putpadding('0', (flag->precision  > 0 ? flag->precision - len : flag->min_width - len), cnt);
	}
	if (p)
		ft_putstr_cnt("0x", cnt);
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', (flag->precision > len ? flag->min_width - flag->precision : flag->min_width - len), cnt);
	return (0);
}

int		ft_putnumstr2(char *t_str, int len, t_flag *flag, int p, int *cnt)
{
	// printf("zero : %d\n", flag->zero_padding);
	// printf("left : %d\n", flag->left_justified);
	// printf("min : %d\n\n", flag->min_width);
	// printf("min : %d\n\n", flag->precision);
	if (flag->min_width && !flag->left_justified && !flag->zero_padding)
	{
		ft_putpadding(' ', (flag->precision > len ? flag->min_width - flag->precision : flag->min_width - len), cnt);
	}
	if (p)
		ft_putstr_cnt("0x", cnt);
	if (flag->precision > 0 || flag->zero_padding)
	{
		if (p)
			len -= 2;
		ft_putpadding('0', (flag->precision  > 0 ? flag->precision - len : flag->min_width - len), cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', (flag->precision > len ? flag->min_width - flag->precision : flag->min_width - len), cnt);
	// printf("zero : %d\n", flag->zero_padding);
	// printf("left : %d\n", flag->left_justified);
	// printf("min : %d\n", flag->min_width);
	// printf("pre : %d\n", flag->precision);
	return (0);
}

void		put_c(va_list *ap, t_flag *flag, int *cnt)
{
	int				t_int;

	t_int = va_arg(*ap, int);
	if (flag->min_width && !flag->left_justified)
	{
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->min_width - 1, cnt);
	}
	ft_putchar_cnt((char)t_int, cnt);
	if (flag->left_justified)
	{
		ft_putpadding(' ', flag->min_width - 1, cnt);
	}
}
