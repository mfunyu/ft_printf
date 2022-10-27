/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2022/10/27 17:24:05 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_s(va_list *ap, t_flag *flag, int *cnt)
{
	char	*t_str;
	int		need_free;

	need_free = 0;
	t_str = va_arg(*ap, char *);
	t_str = (!t_str ? "(null)" : t_str);
	if (0 <= flag->precision && flag->precision < (int)ft_strlen(t_str))
	{
		need_free = 1;
		t_str = ft_substr(t_str, 0, flag->precision);
		if (!t_str)
			return (-1);
	}
	ft_putstr(t_str, ft_strlen(t_str), flag, cnt);
	if (need_free)
		free(t_str);
	return (0);
}

int	set_di(va_list *ap, t_flag *flag, int *cnt)
{
	char	*t_str;
	char	*tmp;

	t_str = ft_itoa(va_arg(*ap, int));
	if (!t_str)
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		t_str = ft_strdup("");
		if (!t_str)
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
		if (*t_str == '-')
			flag->precision++;
	}
	ft_putnumstr(t_str, ft_strlen(t_str), flag, cnt);
	free(t_str);
	return (0);
}

int	set_u(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int	t_uint;
	char			*t_str;
	char			*tmp;

	t_uint = va_arg(*ap, unsigned int);
	t_str = ft_uitoa(t_uint);
	if (!t_str)
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		t_str = ft_strdup("");
		if (!t_str)
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
	}
	ft_putnumstr(t_str, ft_strlen(t_str), flag, cnt);
	free(t_str);
	return (0);
}

int	set_hex(va_list *ap, t_flag *flag, int *cnt)
{
	size_t		t_uint;
	char		*t_str;
	char		*tmp;

	t_uint = (flag->format == 'p' ? \
			(size_t)va_arg(*ap, void *) : va_arg(*ap, unsigned int));
	t_str = ft_utohex(t_uint, (flag->format == 'X' ? 1 : 0));
	if (!t_str)
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		t_str = ft_strdup("");
		if (!t_str)
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
	}
	ft_puthexstr(t_str, ft_strlen(t_str), flag, cnt);
	free(t_str);
	return (0);
}
