/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/13 22:59:24 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_di(va_list *ap, t_flag *flag, int *cnt)
{
	char			*t_str;

	t_str = ft_itoa(va_arg(*ap, int));
	if (!flag->precision && t_str[0] == '0')
	{
		t_str = ft_strdup("");
	}
	if (flag->precision > 0)
		flag->zero_padding = 0;
	ft_putstr2(t_str, ft_strlen(t_str), flag, cnt);
}

void		set_u(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int t_uint;
	char			*t_str;

	t_uint = va_arg(*ap, unsigned int);
	t_str = ft_uitoa(t_uint);
	ft_putstr2(t_str, ft_strlen(t_str), flag, cnt);
}

void		set_hex(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int t_uint;
	char			*t_str;

	t_uint = va_arg(*ap, unsigned int);
	t_str = itohex(t_uint, (flag->format == 'X' ? 1 : 0));
	ft_putstr(t_str, (flag->format == 'p' ? ft_strlen(t_str) + 2 : ft_strlen(t_str)),\
	flag, (flag->format == 'p' ? 1 : 0) , cnt);
}
