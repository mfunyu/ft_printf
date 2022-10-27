/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2022/10/27 20:45:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** expected output
** [     -000007] instead of [     00000-7]
*/

int	ft_putnumstr(char *t_str, int strlen, t_flag *flag, int *cnt)
{
	if (flag->min_width && !flag->left_justified && !flag->zero_padding)
		ft_putpadding(' ', flag->min_width - max(flag->precision, strlen), cnt);
	if (flag->precision > 0 || flag->zero_padding)
	{
		if (*t_str == '-')
		{
			ft_putchar_cnt('-', cnt);
			t_str++;
		}
		if (flag->precision > 0)
			ft_putpadding('0', flag->precision - strlen, cnt);
		else
			ft_putpadding('0', flag->min_width - strlen, cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
		ft_putpadding(' ', flag->min_width - max(flag->precision, strlen), cnt);
	return (0);
}

static void	ft_puthexstr_prefix(int strlen, t_flag *flag, int *cnt, int *p)
{
	int		len;

	*p = 0;
	if (flag->format == 'p')
		*p = 1;
	if (flag->min_width && !flag->left_justified && !flag->zero_padding)
	{
		len = flag->min_width - max(flag->precision, strlen);
		if (*p)
			len -= 2;
		ft_putpadding(' ', len, cnt);
	}
	if (*p)
		ft_putstr_cnt("0x", cnt);
}

int	ft_puthexstr(char *t_str, int strlen, t_flag *flag, int *cnt)
{
	int		len;
	int		p;

	ft_puthexstr_prefix(strlen, flag, cnt, &p);
	if (flag->precision > 0 || flag->zero_padding)
	{
		len = strlen;
		if (p)
			len += 2;
		if (flag->precision > 0)
			ft_putpadding('0', flag->precision - strlen, cnt);
		else
			ft_putpadding('0', flag->min_width - len, cnt);
	}
	ft_putstr_cnt(t_str, cnt);
	if (flag->left_justified)
	{
		len = flag->min_width - max(flag->precision, strlen);
		if (p)
			len -= 2;
		ft_putpadding(' ', len, cnt);
	}
	return (0);
}

void	put_c(va_list *ap, t_flag *flag, int *cnt)
{
	int		t_int;
	char	padding;

	t_int = va_arg(*ap, int);
	padding = ' ';
	if (flag->min_width && !flag->left_justified)
	{
		if (flag->zero_padding)
			padding = '0';
		ft_putpadding(padding, flag->min_width - 1, cnt);
	}
	ft_putchar_cnt((char)t_int, cnt);
	if (flag->left_justified)
	{
		ft_putpadding(padding, flag->min_width - 1, cnt);
	}
}

void	put_s(va_list *ap, t_flag *flag, int *cnt)
{
	char	*t_str;
	int		len;
	char	padding;

	t_str = va_arg(*ap, char *);
	if (!t_str)
		t_str = "(null)";
	len = ft_strlen(t_str);
	if (0 <= flag->precision && flag->precision < len)
		len = flag->precision;
	padding = ' ';
	if (flag->min_width && !flag->left_justified)
	{
		if (flag->zero_padding)
			padding = '0';
		ft_putpadding(padding, flag->min_width - len, cnt);
	}
	ft_putstr_cnt_limit(t_str, len, cnt);
	if (flag->left_justified)
		ft_putpadding(padding, flag->min_width - len, cnt);
}
