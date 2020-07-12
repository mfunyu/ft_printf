/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:19:36 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/12 12:16:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpadding(char c, int n, int *cnt)
{
	while(n > 0)
	{
		ft_putchar_fd(c, 1);
		*cnt++;
		n--;
	}
}

int		ft_putchr(int t_int, t_flag *flag, int *cnt)
{
	if (flag->justified && !flag->left_justified)
		ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - 1, cnt);
	ft_putchar_fd((char)t_int, 1);
	*cnt++;
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
