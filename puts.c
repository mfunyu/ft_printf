/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/12 11:52:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpadding(char c, int n)
{
	while(n > 0)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}

int		ft_putchr(int t_int, t_flag *flag)
{
	if (flag->justified && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - 1);
	ft_putchar_fd((char)t_int, 1);
	if (flag->left_justified)
		ft_putpadding(' ', flag->digits - 1);
	return (0);
}

int		ft_putstr(char *t_str, int len, t_flag *flag, int p)
{
	if (flag->justified && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - len);
	if (p)
		ft_putstr_fd("0x", 1);
	ft_putstr_fd(t_str, 1);
	if (flag->left_justified)
		ft_putpadding(' ', flag->digits - len);
	return (0);
}
