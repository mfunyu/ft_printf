/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/13 20:26:26 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpadding(char c, int n, int *cnt)
{
	while(n > 0)
	{
		ft_putchar_fd(c, 1);
		(*cnt)++;
		n--;
	}
}

int		ft_putchr(int t_int, t_flag *flag, int *cnt)
{
	if (flag->justified && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - 1, cnt);
	ft_putchar_fd((char)t_int, 1);
	(*cnt)++;
	if (flag->left_justified)
		ft_putpadding(' ', flag->digits - 1, cnt);
	return (0);
}

int		ft_putstr(char *t_str, int len, t_flag *flag, int p, int *cnt)
{
	if (flag->justified && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - len, cnt);
	if (p)
	{
		ft_putstr_fd("0x", 1);
		*cnt += 2;
	}
	ft_putstr_fd(t_str, 1);
	*cnt += ft_strlen(t_str);
	if (flag->left_justified)
		ft_putpadding(' ', flag->digits - len, cnt);
	return (0);
}

int		ft_putstr2(char *t_str, int len, t_flag *flag, int *cnt)
{
	if (flag->justified && !flag->left_justified && !flag->zero_padding)
	{
		ft_putpadding(' ', (flag->precision > len ? flag->digits - flag->precision : flag->digits - len), cnt);
	}
	if (flag->precision > 0 || flag->zero_padding)
	{
		if (*t_str == '-')
		{
			ft_putchar_fd('-', 1);
			(*cnt)++;
			t_str++;
		}
		ft_putpadding('0', (flag->precision  > 0 ? flag->precision - len : flag->digits - len), cnt);
	}
	ft_putstr_fd(t_str, 1);
	*cnt += ft_strlen(t_str);
	if (flag->left_justified)
		ft_putpadding(' ', (flag->precision > len ? flag->digits - flag->precision : flag->digits - len), cnt);
	return (0);
}
