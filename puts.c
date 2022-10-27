/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2022/10/27 17:26:35 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *t_str, int len, t_flag *flag, int *cnt)
{
	if (flag->min_width && !flag->left_justified)
	{
		ft_putpadding((flag->zero_padding ? '0' : ' '), \
								flag->min_width - len, cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', flag->min_width - len, cnt);
	return (0);
}

/*
** expected output
** [     -000007] instead of [     00000-7]
*/

int	ft_putnumstr(char *t_str, int strlen, t_flag *flag, int *cnt)
{
	if (flag->min_width && !flag->left_justified && !flag->zero_padding)
	{
		ft_putpadding(' ', flag->min_width - max(flag->precision, strlen), cnt);
	}
	if (flag->precision > 0 || flag->zero_padding)
	{
		if (*t_str == '-')
		{
			ft_putchar_cnt('-', cnt);
			t_str++;
		}
		ft_putpadding('0', (flag->precision > 0 ? \
			flag->precision - strlen : flag->min_width - strlen), cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
	{
		ft_putpadding(' ', flag->min_width - max(flag->precision, strlen), cnt);
	}
	return (0);
}

int	ft_puthexstr(char *t_str, int strlen, t_flag *flag, int *cnt)
{
	int		len;
	int		p;

	p = (flag->format == 'p' ? 1 : 0);
	if (flag->min_width && !flag->left_justified && !flag->zero_padding)
	{
		len = flag->min_width - max(flag->precision, strlen);
		ft_putpadding(' ', (p ? len - 2 : len), cnt);
	}
	if (p)
		ft_putstr_cnt("0x", cnt);
	if (flag->precision > 0 || flag->zero_padding)
	{
		len = (p ? strlen + 2 : strlen);
		ft_putpadding('0', (flag->precision > 0 ? \
			flag->precision - strlen : flag->min_width - len), cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
	{
		len = flag->min_width - max(flag->precision, strlen);
		ft_putpadding(' ', (p ? len - 2 : len), cnt);
	}
	return (0);
}

void	put_c(va_list *ap, t_flag *flag, int *cnt)
{
	int		t_int;

	t_int = va_arg(*ap, int);
	if (flag->min_width && !flag->left_justified)
	{
		ft_putpadding((flag->zero_padding ? '0' : ' '), \
								flag->min_width - 1, cnt);
	}
	ft_putchar_cnt((char)t_int, cnt);
	if (flag->left_justified)
	{
		ft_putpadding(' ', flag->min_width - 1, cnt);
	}
}
