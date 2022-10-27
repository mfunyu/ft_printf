/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2022/10/27 20:42:27 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_di(va_list *ap, t_flag *flag, int *cnt)
{
	char	t_str[100];

	ft_itoa_stack(t_str, va_arg(*ap, int));
	if (!flag->precision && t_str[0] == '0')
	{
		t_str[0] = '\0';
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
		if (*t_str == '-')
			flag->precision++;
	}
	ft_putnumstr(t_str, ft_strlen(t_str), flag, cnt);
	return (0);
}

int	set_u(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int	t_uint;
	char			t_str[100];

	t_uint = va_arg(*ap, unsigned int);
	ft_uitoa(t_str, t_uint);
	if (!flag->precision && t_str[0] == '0')
	{
		t_str[0] = '\0';
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
	}
	ft_putnumstr(t_str, ft_strlen(t_str), flag, cnt);
	return (0);
}

int	set_hex(va_list *ap, t_flag *flag, int *cnt)
{
	size_t		t_uint;
	char		t_str[100];

	if (flag->format == 'p')
		t_uint = (size_t)va_arg(*ap, void *);
	else
		t_uint = va_arg(*ap, unsigned int);
	ft_utohex(t_str, t_uint, flag->format == 'X');
	if (!flag->precision && t_str[0] == '0')
	{
		t_str[0] = '\0';
	}
	if (flag->precision >= 0)
		flag->zero_padding = 0;
	ft_puthexstr(t_str, ft_strlen(t_str), flag, cnt);
	return (0);
}
