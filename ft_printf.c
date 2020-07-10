/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/10 18:57:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

//cspdiuxX%

t_flag	*init_struct()
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));

	flag->left_justified = 0;
	flag->justified = 0;
	flag->right_justified = 0;
	flag->zero_padding = 0;
	flag->precision = 0;
	flag->digits = 0;

	return (flag);
}

void	ft_putpadding(char c, int n)
{
	while(n > 0)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}

int		parse_format_str(const char *format, va_list *ap, t_flag *flag)
{
	int		i;
	// int		type;
	int		t_int;
	int		t_uint;
	char	*t_str;

	i = 0;

	if (format[i] == 'c')
	{
		t_int = va_arg(*ap, int);
		if (flag->justified && !flag->left_justified)
			ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - 1);
		ft_putchar_fd((char)t_int, 1);
		if (flag->left_justified)
			ft_putpadding(' ', flag->digits - 1);
	}
	if (format[i] == 's')
	{
		t_str = va_arg(*ap, char *);
		if (flag->justified && !flag->left_justified)
			ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - ft_strlen(t_str));
		ft_putstr_fd(t_str, 1);
		if (flag->left_justified)
			ft_putpadding(' ', flag->digits - ft_strlen(t_str));
	}
	if (format[i] == 'p')
	{
		t_uint = va_arg(*ap, unsigned int);
		ft_putstr_fd("0x", 1);
	}
	if (format[i] == 'd' || format[i] == 'i')
	{
		int		len;

		t_str = ft_itoa(va_arg(*ap, int));
		len = (flag->precision > (int)ft_strlen(t_str) ? flag->precision : ft_strlen(t_str));
		if (flag->justified && !flag->left_justified)
			ft_putpadding((flag->zero_padding ? '0' : ' '), flag->digits - len);
		if (flag->precision)
			ft_putpadding('0', flag->precision - ft_strlen(t_str));
		ft_putstr_fd(t_str, 1);
		if (flag->left_justified)
			ft_putpadding(' ', flag->digits - len);
	}
	if (format[i] == '%')
	{
		ft_putchar_fd(format[i], 1);
	}
	if (format[i] == 'u')
	{
		t_uint = va_arg(*ap, unsigned int);
		ft_putnbr_fd(t_uint, 1);
	}
	if (format[i] == 'x')
	{
		t_uint = va_arg(*ap, unsigned int);
		ft_putnbr_fd(t_uint, 1);
	}
	if (format[i] == 'X')
	{
		t_uint = va_arg(*ap, unsigned int);
		ft_putnbr_fd(t_uint, 1);
	}
	return (0);
}

//  '-0.*'

const char	*parse_flags(const char *format, va_list *ap, t_flag *flag)
{
	int		i;

	i = 0;
	while (ft_strchr("-0.*", format[i]) || ft_isdigit(format[i]))
	{
		if (format[i] == '-')
		{
			flag->left_justified = 1;
			flag->justified = 1;
		}
		else if (format[i] == '0')
		{
			flag->justified = 1;
			flag->zero_padding = 1;
		}
		else if (format[i] == '.')
		{
			if (ft_isdigit(format[i + 1]))
			{
				i++;
				flag->precision = ft_atoi(format + i);
				i += ft_strlen(ft_itoa(flag->precision)) - 1;
				flag->zero_padding = 0;
			}
		}
		else if (format[i] == '*')
		{
			flag->digits = va_arg(*ap, int);
			flag->justified = 1;
		}
		else if (ft_isdigit(format[i]))
		{
			flag->justified = 1;
			flag->digits = ft_atoi(format + i);
			i += ft_strlen(ft_itoa(flag->digits)) - 1;
		}
		i++;
	}
	if (flag->left_justified)
	{
		flag->zero_padding = 0;
	}
	return (format + i);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_flag		*flag;
	int			cnt;

	cnt = 0;
	va_start(ap, str);
	flag = init_struct();
	while (*str)
	{
		if (*str == '%')
		{
			str = parse_flags(str + 1, &ap, flag);
			parse_format_str(str, &ap, flag);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}
